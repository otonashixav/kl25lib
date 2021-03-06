#include "uart0.h"

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

#include "__generic_uart.h"
