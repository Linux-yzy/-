/**
 * @file disp_manager.c
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-05 09-38-54          Byron
 */
#include "disp_manager.h"

static PDispOpr g_DispDevs    = NULL;
static PDispOpr g_DispDefault = NULL;
static DispBuff g_tDispBuff;
static struct fb_var_screeninfo var;	
unsigned int line_width,screen_size;
unsigned char *fb_base;

void lcd_put_pixel(int x, int y, unsigned int color)
{
  unsigned char   *pen_8 = fb_base +(y*g_tDispBuff.iXres + x)*g_tDispBuff.iBpp/8;
  unsigned short  *pen_16;
  unsigned int    *pen_32;

  unsigned int red, green, blue;	

  pen_16 = (unsigned short *)pen_8;
  pen_32 = (unsigned int *)pen_8;

  switch(g_tDispBuff.iBpp)
  {
    case 8:
    {
        *pen_8 = color;
        break;
    }
		
	case 16:
	{
		/* 565 */
		red   = (color >> 16) & 0xff;
		green = (color >> 8) & 0xff;
		blue  = (color >> 0) & 0xff;
		color = ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3);
		*pen_16 = color;
		break;
	}
	case 32:
	{
		*pen_32 = color;
		break;
	}
	default:
	{
		printf("can't surport %dbpp\n", g_tDispBuff.iBpp);
		break;
	}
  
  }
}

void RegisterDisplay(PDispOpr ptDispOpr)
{
    ptDispOpr->ptNext = g_DispDevs;
    g_DispDevs = ptDispOpr;
}

int SelectDefaultDisplay(char *name)
{
    PDispOpr pTmp = g_DispDevs;

    while(pTmp)
    {
        if(strcmp(name, pTmp->name) == 0)
        {
             g_DispDefault = pTmp;
             return 0;
        }

        pTmp = pTmp->ptNext;
    }

    return -1;
}

int InitDefaultDisplay(void)
{
    int ret;
   
    ret = g_DispDefault->DeviceInit();
    if(ret)
    {
		printf("DeviceInit err\n");
		return -1;        
    }

    ret = g_DispDefault->GetBuffer(&g_tDispBuff);
    if(ret)
    {
        printf("GetBuffer err");
        return -1;
    }
}

int FlushDisplayRegion(PRegion ptRegion, PDispBuff ptDispBuff)
{
	return g_DispDefault->FlushRegion(ptRegion, ptDispBuff);
}

void DisplayInit(void)
{
	FramebufferInit();
}
