#include "RTOS_cfg.h"
  const RTOS_Task_t	RTOS_strTaskArray[RTOS_enuTaskNumber] =
{
	[RTOS_enuTaskLed1Toggle] =
							{
								.periodicity = 100,
								.TaskFunction = Task1CallFunction
							},
	[RTOS_enuTaskLed2Toggle] =
							{
								.periodicity = 200,
								.TaskFunction = Task2CallFunction
							}
};