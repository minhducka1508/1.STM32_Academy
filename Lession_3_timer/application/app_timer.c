#include "app_timer.h"

static app_timer_t *s_timer_list[MAX_APP_TIMERS];
static uint8_t s_timer_counter = 0;

void app_timer_register(app_timer_t *t)
{
	if(s_timer_counter < MAX_APP_TIMERS)
	{
		s_timer_list[s_timer_counter] = t;
		s_timer_counter++;
	}
}

void app_timer_init(app_timer_t *t, TIM_HandleTypeDef *htim, uint32_t period_ms)
{
	t->htim = htim;
	t->period_ms = period_ms;
	t->counter_ms = 0;
	t->elapsed = 0;
	t->timeout_flag = false;
	app_timer_register(t);
}

void app_timer_start(app_timer_t *t)
{
	__HAL_TIM_SET_COUNTER(t->htim, 0);
	HAL_TIM_Base_Start_IT(t->htim);
}

void app_timer_stop(app_timer_t *t)
{
	HAL_TIM_Base_Stop_IT(t->htim);
}

bool app_timer_is_expired(app_timer_t *t)
{
	if (t->timeout_flag == true)
	{
		t->timeout_flag = false;
		return true;
	}
	return false;
}

uint32_t app_timer_get_tick(app_timer_t *t)
{
	return t->elapsed;
}

void app_timer_callback(TIM_HandleTypeDef  *htim)
{
	for(int i = 0; i < s_timer_counter; i++)
	{
		if (s_timer_list[i]->htim->Instance == htim->Instance)
		{
			if (++s_timer_list[i]->counter_ms >= s_timer_list[i]->period_ms)
			{
				s_timer_list[i]->timeout_flag = true;
				s_timer_list[i]->counter_ms = 0;
				s_timer_list[i]->elapsed++;
			}
		}
	}
}
