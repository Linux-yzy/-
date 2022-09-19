/**
 * @file touchscreen.c
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-12 08-37-19          Byron
 */
#include "input_manager.h"
#include <tslib.h>

static struct tsdev *ts;

static  int  TouchscreenDeviceInit(void)
{
	ts = ts_setup(NULL, 0);
	if (!ts)
	{
		printf("ts_setup err\n");
		return -1
	}

    return 0;
}
static  int  TouchscreenDeviceExit(void)
{
	ts_close(g_ts);
	return 0;
}
static  int  TouchscreenGetInputEvent(PInputEvent ptInputEvent)
{
    struct ts_sample samp;
    int ret;

    ret = ts_read(g_ts, &samp, 1);
    if(ret != 1)
    {
        return -1;
    }

	ptInputEvent->iType     = INPUT_TYPE_TOUCH;
	ptInputEvent->iX        = samp.x;
	ptInputEvent->iY        = samp.y;
	ptInputEvent->iPressure = samp.pressure;
	ptInputEvent->tTime     = samp.tv;

	return 0;
}

static InputDevice g_tTouchscreenDev = {
	.name = "touchscreen",
	.GetInputEvent  = TouchscreenGetInputEvent,
	.DeviceInit     = TouchscreenDeviceInit,
	.DeviceExit     = TouchscreenDeviceExit,
};
