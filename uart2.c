#include "uart2.h"
#include "common.h"
#include "MKL25Z4.h"

// configurables
#define UART_CLOCK_MASK SIM_SCGC4_UART2_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 22
#define TX_PIN_MUX PORT_PCR_MUX(4)
#define RX_PIN 23
#define RX_PIN_MUX PORT_PCR_MUX(4)
#define UART UART2
#define UART_IRQ UART2_IRQ
#define UART_MODULE_NAME uart2
#include "generic_uart.h"