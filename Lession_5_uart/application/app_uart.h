#ifndef _APP_UART_H_
#define _APP_UART_H_

#include "main.h"
typedef enum
{
	// map from HAL_StatusTypeDef
	UART_OK = 0x00U,
	UART_ERROR = 0x01U,
	UART_BUSY = 0x02U,
	UART_TIMEOUT = 0x03U
} uart_status_e;

extern UART_HandleTypeDef huart1;

uart_status_e send_message(uint8_t data, uint32_t send_time_out);
uart_status_e recv_message(uint8_t *data, uint32_t recv_time_out);
uart_status_e send_string(const char *str, uint32_t send_time_out);
uart_status_e recv_string(uint8_t *buffer, uint32_t max_length, uint32_t recv_time_out);

#endif /* _APP_UART_H_ */
