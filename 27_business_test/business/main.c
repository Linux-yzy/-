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
#include <stdlib.h>

#include "disp_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "page_manager.h"

int main(int argc, char **argv)
{
	printf("000");
    int       error;
printf("00");
	if (argc != 2)
	{
		printf("Usage: %s <font_file>\n", argv[0]);
		return -1;
	}
printf("0");
    /*初始化显示系统*/
	DisplayInit();
printf("1");
	SelectDefaultDisplay("fb");
printf("2");
	InitDefaultDisplay();
printf("3");
//	ptBuffer = GetDisplayBuffer();
printf("4");
    /* 初始化文字系统 */
	FontsRegister();
printf("5");	
	error = SelectAndInitFont("freetype", argv[1]);
	if (error)
	{
		printf("SelectAndInitFont err\n");
		return -1;
	}
printf("6");
    /* 初始化输入系统 */
	InputRegister();
	IntpuDeviceInit();
printf("7");
    /*初始化页面系统*/
	PagesRegister();
printf("8");
    /*运行业务系统的主页面*/
	Page("main")->Run(NULL);

	return 0;	
}
