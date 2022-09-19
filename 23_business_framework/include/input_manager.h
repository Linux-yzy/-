/**
 * @file input_manager.h
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-12 05-42-40          Byron
 */
#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include <sys/time.h>

#define INPUT_TYPE_TOUCH 1
#define INPUT_TYPE_NET   2

typedef struct InputEvent{
    struct timeval tTime;
    int iType;
    int iX;
    int iY;
    int iPressure;
    char str[1024];
}InputEvent, *PInputEvent;

typedef struct InputDevice{
    char *name;
    int  (*DeviceInit)(void);
    int  (*DeviceExit)(void);
    int  (*GetInputEvent)(PInputEvent ptInputEvent);
    struct InputDevice *ptNext;
}InputDevice, *PInputDevice;


#endif
