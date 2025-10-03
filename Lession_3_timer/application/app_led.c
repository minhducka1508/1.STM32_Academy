#include "app_led.h"

void blink_led_blocking(GPIO_TypeDef *led_port, uint16_t led_pin)
{
	HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_RESET);
	HAL_Delay(100);
}

void blink_led_non_blocking(GPIO_TypeDef *led_port, uint16_t led_pin, uint32_t period, uint32_t on_duration)
{
	static uint32_t last_change = 0;
	static uint8_t led_state = 0;

	uint32_t now = HAL_GetTick();

	if (led_state == 1)
	{
		if (now - last_change >= on_duration)
		{
			HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_RESET);
			led_state = 0;
			last_change = now;
		}
	}
	else
	{
		if ((now - last_change) >= (period - on_duration))
		{
			HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_SET);
			led_state = 1;
			last_change = now;
		}
	}
}
