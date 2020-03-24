#include "uart1.h"

#define UART_CLOCK_MASK SIM_SCGC4_UART1_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 0
#define TX_PIN_MUX 3
#define RX_PIN 1
#define RX_PIN_MUX 3
#define UART UART1
#define UART_IRQ UART1_IRQ
#define IRQ_PRIORITY 1
#define UART_MODULE_NAME uart1

#include "__generic_uart.h"
