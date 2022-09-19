/**
 * @file disp_manager.h
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-04 09-33-13          Byron
 */
#ifndef _DISP_MANAGER_H
#define _DISP_MANAGER_H

typedef struct DispBuff{
    int iXres;
    int iYres;
    int iBpp;
    char *buff;
}DispBuff, *PDispBuff;

typedef struct Region{
    int iLeftUpX;
    int iLeftUpY;
    int iWidth;
    int iHeigh;
}Region, *PRegion;

typedef struct DispOpr{
    char *name;
    int  (*DeviceInit)(void);
    int  (*DeviceExit)(void);
    char (*GetBuffer)(PDispBuff ptDispBuff);
    int  (*FlushRegion)(PRegion ptRegion, PDispBuff ptDispBuff);
    struct DispOpr *ptNext;
}DispOpr, *PDispOpr;


#endif
