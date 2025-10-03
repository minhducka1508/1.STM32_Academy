#include "app_uart.h"

UART_HandleTypeDef huart1;

uart_status_e send_message(uint8_t data, uint32_t send_time_out)
{
	HAL_StatusTypeDef result = HAL_UART_Transmit(&huart1, &data, 1, send_time_out);
	return result;
}

uart_status_e recv_message(uint8_t *data, uint32_t recv_time_out)
{
	HAL_StatusTypeDef result = HAL_UART_Receive(&huart1, data, 1, recv_time_out);
	return result;
}

uart_status_e send_string(const char *str, uint32_t send_time_out)
{
	while (*str != '\0')
	{
		uart_status_e send_status = send_message((uint8_t)(*str), send_time_out);
		if (send_status != UART_OK)
		{
			return send_status;
		}
		str++;
	}
	return UART_OK;
}

uart_status_e recv_string(uint8_t *buffer, uint32_t max_length, uint32_t recv_time_out)
{
	uint32_t index = 0;

	while (index < (max_length - 1))
	{
		uart_status_e recv_status = recv_message(&buffer[index], recv_time_out);
		if (recv_status != UART_OK)
		{
			return recv_status;
		}

		if (buffer[index] == '\n') // dừng khi gặp newline
			break;

		index++;
	}

	buffer[index] = '\0';
	return UART_OK;
}