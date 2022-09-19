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

#include "font_manager.h"

typedef struct DispBuff{
    int iXres;
    int iYres;
    int iBpp;
    char *buff;
}DispBuff, *PDispBuff;

typedef struct DispOpr{
    char *name;
    int  (*DeviceInit)(void);
    int  (*DeviceExit)(void);
    char (*GetBuffer)(PDispBuff ptDispBuff);
    int  (*FlushRegion)(PRegion ptRegion, PDispBuff ptDispBuff);
    struct DispOpr *ptNext;
}DispOpr, *PDispOpr;

void RegisterDisplay(PDispOpr ptDispOpr);

void DisplayInit(void);
int SelectDefaultDisplay(char *name);
int InitDefaultDisplay(void);
void lcd_put_pixel(int x, int y, unsigned int color);
int FlushDisplayRegion(PRegion ptRegion, PDispBuff ptDispBuff);
PDispBuff GetDisplayBuffer(void);
void DrawFontBitMap(PFontBitMap ptFontBitMap, unsigned int dwColor);
void DrawRegion(PRegion ptRegion, unsigned int dwColor);
void DrawTextInRegionCentral(char *name, PRegion ptRegion, unsigned int dwColor);

#endif
