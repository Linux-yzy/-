/**
 * @file page_manager.h
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-18 02-16-53          Byron
 */
#ifndef _PAGE_MANAGER_H
#define _PAGE_MANAGER_H

typedef struct PageAction {
	char *name;
	void (*Run)(void *pParams);
	struct PageAction *ptNext;
}PageAction, *PPageAction;

void PageRegister(PPageAction ptPageAction);
void PagesRegister(void);
PPageAction Page(char *name); //必须加这个声明page_test.c:17:14: error: invalid type argument of '->' (have 'int')


#endif




