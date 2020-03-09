#ifndef UART2_H
#define UART2_H
typedef unsigned int uint32_t;

#define UART_CLOCK_MASK SIM_SCGC4_UART2_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTE_MASK
#define PORT PORTE
#define TX_PIN 22
#define TX_PIN_MUX 4
#define RX_PIN 23
#define RX_PIN_MUX 4
#define UART UART2
#define UART_IRQ UART2_IRQ
#define UART_MODULE_NAME uart2

/**
 * Initiates the UART2 module with a specified baud rate
 * @param [in] baud_rate the baud rate of the serial communications
 */
void uart2_init(uint32_t baud_rate);

/**
 * Retrieves the next byte of data in the receive buffer and places it into
 * an unsigned char, returning 0 on success and 1 on failure (buffer empty)
 * @param [in/out] data  the location to store the data retrieved
 * @return 0 on success, 1 on failure (buffer empty)
 */
int uart2_receive(unsigned char *data);

/**
 * Transmits a byte of data by placing it into the transmit buffer. Returns 0
 * on success and 1 on failure (buffer full)
 * @param [in] data  the data to be sent
 * @return 0 on success, 1 on failure (buffer full)
 */
int uart2_transmit(unsigned char data);

/**
 * Flushes the receive buffer
 */
void uart2_flush_buffer(void);

/**
 * Returns 0 if no overflow has occurred and 1 if some data has been dropped
 * due to full buffer since this function was last called or the buffer was
 * last cleared
 */
int uart2_overflow_flag(void);
#endif // UART2_H
