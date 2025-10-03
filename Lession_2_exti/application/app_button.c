#include "app_button.h"

button_t btn_1 = {GPIOC, GPIO_PIN_13, 0, 0};

button_state_t read_button_polling(button_t *btn)
{
	button_state_t state_press = BUTTON_RELEASED;
	if (HAL_GPIO_ReadPin(btn->port, btn->pin) == GPIO_PIN_RESET)
	{
		state_press = BUTTON_PRESSED;
	}

	return state_press;
}

button_state_t debounce_button(button_t *btn)
{
	uint32_t time_now = HAL_GetTick();
	button_state_t press_present = read_button_polling(btn);
	static button_state_t last_raw;

	if (press_present != last_raw)
	{
		last_raw = press_present;
		btn->time_change = time_now;
	}

	if (time_now - btn->time_change >= TIMEOUT_DEBOUNCE_BTN_MS)
	{
		btn->stable_state = press_present;
	}

	return btn->stable_state;
}
