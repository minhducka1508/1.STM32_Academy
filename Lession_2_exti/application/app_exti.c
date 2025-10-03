#include "app_exti.h"

btn_event_t btn_event_flag = BTN_EVENT_NONE;

btn_event_t btn_handle_irq(button_t *btn)
{
	static uint32_t time_press = 0;
	if (read_button_polling(btn) == BUTTON_PRESSED)
	{
		time_press = HAL_GetTick();
		return BTN_EVENT_NONE;
	}
	else
	{
		uint32_t duration = HAL_GetTick() - time_press;
		if (duration >= TIME_LONG_PRESS_MS)
		{
			return BTN_EVENT_LONG;
		}
		else
		{
			return BTN_EVENT_SHORT;
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_13)
	{
		btn_event_flag = btn_handle_irq(&btn_1);
	}
}
