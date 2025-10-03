#ifndef _APP_EXTI_H_
#define _APP_EXTI_H_

#include "app_button.h"
#include "app_led.h"

#define TIME_LONG_PRESS_MS 500

extern btn_event_t btn_event_flag;

btn_event_t btn_handle_irq(button_t *btn);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* _APP_EXTI_H_ */