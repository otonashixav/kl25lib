#include "common.h"
#include "MKL25Z4.h"

#ifndef UART_CLOCK_MASK
#error Missing #define UART_CLOCK_MASK
#endif
#ifndef PORT_CLOCK_MASK
#error Missing #define PORT_CLOCK_MASK
#endif
#ifndef PORT
#error MISSING #define PORT
#endif
#ifndef TX_PIN
#error MISSING #define TX_PIN
#endif
#ifndef TX_PIN_MUX
#error MISSING #define TX_PIN_MUX
#endif
#ifndef RX_PIN
#error MISSING #define RX_PIN
#endif
#ifndef RX_PIN_MUX
#error MISSING #define RX_PIN_MUX
#endif
#ifndef UART
#error MISSING #define UART
#endif
#ifndef UART_IRQ
#error MISSING #define UART_IRQ
#endif
#ifndef IRQ_PRIORITY
#error MISSING #define IRQ_PRIORITY
#endif
#ifndef UART_MODULE_NAME
#error MISSING #define UART_MODULE_NAME
#endif

// non-configurables; technically UART0 supports variable oversampling but whatever
#define OVERSAMPLING_RATE 16
#ifdef UART0_H
#define UART_CLOCK DEFAULT_SYSTEM_CLOCK
#else
#define UART_CLOCK (DEFAULT_SYSTEM_CLOCK / 2)
#endif

#define DIVISOR(BAUD_RATE) (((UART_CLOCK) / ((BAUD_RATE) * ((OVERSAMPLING_RATE) / 2)) + 1) / 2)

// define queues
#define QUEUE_TYPE data_queue
#define QUEUE_DATA_TYPE volatile uint8_t
#define QUEUE_MAX_SIZE 255
#include "__generic_queue.h"

// static data_queue transmit_buffer = {{0}, 0, 0, 0};
static data_queue receive_buffer = {{0}, 0, 0, 0};

static int overflow_flag = 0;

IRQ(UART_IRQ, 
    if (UART->S1 & UART_S1_RDRF_MASK) { // data to receive
        overflow_flag |= data_queue_push(&receive_buffer, UART->D); // 1 on full buffer
    }
    /*
    if (UART->S1 & UART_S1_TDRE_MASK) { // able to transmit
        if (!data_queue_is_empty(&transmit_buffer)) {
            data_queue_pop(&transmit_buffer, &(UART->D));
        }
    }*/
)

#define INIT(N) CONCAT(N, _init)
void INIT(UART_MODULE_NAME)(uint32_t baud_rate) {
    // Disable all transmitter/receivers
    // UART->C2 &= ~((uint8_t) (UART_C2_TE_MASK | UART_C2_RE_MASK | UART_C2_TIE_MASK | UART_C2_RIE_MASK));

    // Extra UART0 specific config
    #ifdef UART0_H
    SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
    UART->C4 = UART0_C4_OSR(OVERSAMPLING_RATE);
    #endif

    // Enable required clock gates
    SIM->SCGC4 |= UART_CLOCK_MASK;
    SIM->SCGC5 |= PORT_CLOCK_MASK;

    // Set pins to UART
    // PORT->PCR[TX_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[RX_PIN] &= ~PORT_PCR_MUX_MASK;
    // PORT->PCR[TX_PIN] |= PORT_PCR_MUX(TX_PIN_MUX);
    PORT->PCR[RX_PIN] |= PORT_PCR_MUX(RX_PIN_MUX);
    
    // Set baud rate
    UART->BDH = UART_BDH_SBR(DIVISOR(baud_rate) >> 8);
    UART->BDL = UART_BDL_SBR(DIVISOR(baud_rate));

    // Should be configurable?
    // Usables are parity enable/select (C1), rx (S2) and tx (C3) inverts
    UART->C1 = UART->S2 = UART->C3 = 0;

    // Enable everything
    ENABLE_IRQ(UART_IRQ, IRQ_PRIORITY);
    UART->C2 |= UART_C2_RE_MASK | UART_C2_RIE_MASK; // UART_C2_TE_MASK | UART_C2_RE_MASK | UART_C2_TIE_MASK | UART_C2_RIE_MASK;
}

#define RECEIVE(N) CONCAT(N, _receive)
int RECEIVE(UART_MODULE_NAME)(unsigned char *data) {
    return data_queue_pop(&receive_buffer, data);
}

#define TRANSMIT(N) CONCAT(N, _transmit)
int TRANSMIT(UART_MODULE_NAME)(unsigned char data) {
    return 0; // data_queue_push(&transmit_buffer, data);
}

#define FLUSH(N) CONCAT(N, _flush)
void FLUSH(UART_MODULE_NAME)(void) {
    data_queue_clear(&receive_buffer); // clear buffer
    overflow_flag = 0;
}

#define OVERFLOW_FLAG(N) CONCAT(N, _overflow_flag)
int OVERFLOW_FLAG(UART_MODULE_NAME)(void) {
    int flag = overflow_flag;
    overflow_flag = 0;
    return flag;
}
