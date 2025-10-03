#ifndef _APP_LED_H_
#define _APP_LED_H_

#include "main.h"

#define LED_PORT 						GPIOA
#define LED_PIN 						GPIO_PIN_5

void blink_led_blocking(GPIO_TypeDef *led_port, uint16_t led_pin);
void blink_led_non_blocking(GPIO_TypeDef *led_port, uint16_t led_pin, uint32_t period, uint32_t on_duration);

#endif /* _APP_LED_H_ */