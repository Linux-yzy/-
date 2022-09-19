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

typedef struct Region{
    int iLeftUpX;
    int iLeftUpY;
    int iWidth;
    int iHeigh;
}Region, *PRegion;

typedef struct DispOpr{
    char *name;
    char *GetBuffer(int *pXres, int *pYres, int *pBpp);
    int   FlushRegion(PRegion ptRegion, char *buffer);
    struct DispOpr *ptNext;
};

#endif
