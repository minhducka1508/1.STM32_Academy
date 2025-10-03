#ifndef _APP_TIMER_H_
#define _APP_TIMER_H_

#include "main.h"

#define MAX_APP_TIMERS						(10)

typedef struct
{
	TIM_HandleTypeDef *htim;
	uint32_t period_ms;
	volatile uint32_t counter_ms;
	volatile uint32_t elapsed;
	bool timeout_flag;
} app_timer_t;

void app_timer_register(app_timer_t *t);
void app_timer_init(app_timer_t *t, TIM_HandleTypeDef *htim, uint32_t period_ms);
void app_timer_start(app_timer_t *t);
void app_timer_stop(app_timer_t *t);
bool app_timer_is_expired(app_timer_t *t);
uint32_t app_timer_get_tick(app_timer_t *t);
void app_timer_callback(TIM_HandleTypeDef *htim);

#endif /* _APP_TIMER_H_ */