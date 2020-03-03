#include <stdint.h>
#ifndef UART1_H
#define UART1_H
/**
 * Initiates the UART1 module with a specified baud rate
 * @param [in] baud_rate the baud rate of the serial communications
 */
void uart1_init(uint32_t baud_rate);

/**
 * Retrieves the next byte of data in the receive buffer and places it into
 * an unsigned char, returning 0 on success and 1 on failure (buffer empty)
 * @param [in/out] data  the location to store the data retrieved
 * @return 0 on success, 1 on failure (buffer empty)
 */
int uart1_receive(unsigned char *data);

/**
 * Transmits a byte of data by placing it into the transmit buffer. Returns 0
 * on success and 1 on failure (buffer full)
 * @param [in] data  the data to be sent
 * @return 0 on success, 1 on failure (buffer full)
 */
int uart1_transmit(unsigned char data);

/**
 * Flushes the receive buffer
 */
void uart1_flush_buffer(void);

/**
 * Returns 0 if no overflow has occurred and 1 if some data has been dropped
 * due to full buffer since this function was last called or the buffer was
 * last cleared
 */
int uart1_overflow_flag(void);
#endif
