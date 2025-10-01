#ifndef _APP_BUTTON_H_
#define _APP_BUTTON_H_

#include "main.h"
#include "stdint.h"
#include "stdbool.h"

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	uint32_t time_change;
	uint32_t stable_state;
} button_t;

extern button_t btn_1;

bool read_button_polling(button_t *btn);
bool debounce_button(button_t *btn);

#endif /* _APP_BUTTON_H_ */
