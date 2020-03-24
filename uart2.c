#include "uart2.h"

#define UART_CLOCK_MASK SIM_SCGC4_UART2_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 22
#define TX_PIN_MUX 4
#define RX_PIN 23
#define RX_PIN_MUX 4
#define UART UART2
#define UART_IRQ UART2_IRQ
#define IRQ_PRIORITY 1
#define UART_MODULE_NAME uart2

#include "__generic_uart.h"
