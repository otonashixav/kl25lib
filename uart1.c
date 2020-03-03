#include "uart1.h"
#include "common.h"
#include "MKL25Z4.h"

// configurables
#define UART_CLOCK_MASK SIM_SCGC4_UART1_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 0
#define TX_PIN_MUX PORT_PCR_MUX(4)
#define RX_PIN 1
#define RX_PIN_MUX PORT_PCR_MUX(4)
#define UART UART1
#define UART_IRQ UART1_IRQ
#define UART_MODULE_NAME uart1
#include "generic_uart.h"