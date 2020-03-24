#ifndef UART0_H
#define UART0_H

#define UART_CLOCK_MASK SIM_SCGC4_UART0_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 20
#define TX_PIN_MUX 4
#define RX_PIN 21
#define RX_PIN_MUX 4
#define UART UART0
#define UART_IRQ UART0_IRQ
#define IRQ_PRIORITY 1
#define UART_MODULE_NAME uart0

typedef unsigned int uint32_t;
/**
 * Initiates the UART0 module with a specified baud rate
 * @param [in] baud_rate the baud rate of the serial communications
 */
void uart0_init(uint32_t baud_rate);

/**
 * Retrieves the next byte of data in the receive buffer and places it into
 * an unsigned char, returning 0 on success and 1 on failure (buffer empty)
 * @param [in/out] data  the location to store the data retrieved
 * @return 0 on success, 1 on failure (buffer empty)
 */
int uart0_receive(unsigned char *data);

/**
 * Transmits a byte of data by placing it into the transmit buffer. Returns 0
 * on success and 1 on failure (buffer full)
 * @param [in] data  the data to be sent
 * @return 0 on success, 1 on failure (buffer full)
 */
int uart0_transmit(unsigned char data);

/**
 * Flushes the receive buffer
 */
void uart0_flush_buffer(void);

/**
 * Returns 0 if no overflow has occurred and 1 if some data has been dropped
 * due to full buffer since this function was last called or the buffer was
 * last cleared
 */
int uart0_overflow_flag(void);
#endif // UART0_H
