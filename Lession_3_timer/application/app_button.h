#ifndef _APP_BUTTON_H_
#define _APP_BUTTON_H_

#include "main.h"
#include "stdint.h"
#include "stdbool.h"

#define TIMEOUT_DEBOUNCE_BTN_MS (20)

typedef enum
{
	BUTTON_RELEASED = 0, // không nhấn
	BUTTON_PRESSED		 // đang nhấn
} button_state_t;

typedef enum
{
	BTN_EVENT_NONE = 0,
	BTN_EVENT_SHORT,
	BTN_EVENT_LONG
} btn_event_t;

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	uint32_t time_change;
	button_state_t stable_state;
} button_t;

extern button_t btn_1;

button_state_t read_button_polling(button_t *btn);
button_state_t debounce_button(button_t *btn);

#endif /* _APP_BUTTON_H_ */
