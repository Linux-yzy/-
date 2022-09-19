/**
 * @file font_manager.h
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-17 12-58-45          Byron
 */
#ifndef _FONT_MANAGER_H
#define _FONT_MANAGER_H

#include "common.h"

typedef struct FontBitMap {
    Region tRegion;
	int iCurOriginX;
	int iCurOriginY;
	int iNextOriginX;
	int iNextOriginY;
	unsigned char *pucBuffer; //位图数据
}FontBitMap, *PFontBitMap;

typedef struct FontOpr {
	char *name;
	int (*FontInit)(char *aFineName);
	int (*SetFontSize)(int iFontSize);
	int (*GetFontBitMap)(unsigned int dwCode, PFontBitMap ptFontBitMap);
	struct FontOpr *ptNext;
}FontOpr, *PFontOpr;



void RegisterFont(PFontOpr ptFontOpr);

void FontsRegister(void);

int SelectAndInitFont(char *aFontOprName, char *aFontFileName);
int SetFontSize(int iFontSize);
int GetFontBitMap(unsigned int dwCode, PFontBitMap ptFontBitMap);




#endif
