/**
 * @file copy.c
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-07-04 10-32-23          Byron
 */
#include <stdio.h>    //man 3 printf
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include "disp_manageer.h"

static struct fb_var_screeninfo var;	
static unsigned int line_width,screen_size;
static unsigned char *fb_base;
static int fd_old;

static int  FbDeviceInit(void)
{
  
    fd_old = open("/dev/fb0", O_RDWR);
    if(fd_old < 0){
        printf("can not open /dev/fb0\n");
        return -1;
    }

    if(ioctl(fd_old, FBIOGET_VSCREENINFO, &var))
    {
        printf("can not get var from screen");
        return -1;
    }

    line_width  = var.xres * var.bits_per_pixel/8;
    screen_size = var.yres * line_width;
    fb_base = (unsigned char *)mmap(NULL, screen_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_old, 0);
    if(fb_base == (unsigned char *)-1){
        printf("can not mmp success.r\n");
        return -1;
    }

    return 0;
}

static int  DeviceExit(void)
{
	munmap(fb_base, screen_size);
	close(fd_old);

	return 0;
}
/* 可以返回LCD的framebuffer, 以后上层APP可以直接操作LCD, 可以不用FbFlushRegion
 * 也可以malloc返回一块无关的buffer, 要使用FbFlushRegion
 */
static char FbGetBuffer(PDispBuff ptDispBuff)
{
	ptDispBuff->iXres = var.xres;
	ptDispBuff->iYres = var.yres;
	ptDispBuff->iBpp  = var.bits_per_pixel;
	ptDispBuff->buff  = fb_base;
	return 0;
}

static int  FbFlushRegion(PRegion ptRegion, char *buffer)
{
    return 0;
}

static DispOpr g_tFramebufferOpr ={
	.name        = "fb",
	.DeviceInit  = FbDeviceInit,
	.DeviceExit  = FbDeviceExit,
	.GetBuffer   = FbGetBuffer,
	.FlushRegion = FbFlushRegion,
};

void FramebufferInit(void)
{
    RegisterDisplay(&g_tFramebufferOpr);    
}

