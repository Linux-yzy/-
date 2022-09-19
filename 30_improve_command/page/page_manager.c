/**
 * @file page_manager.c
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-18 02-12-13          Byron
 */
#include <page_manager.h>
#include <string.h>

static PPageAction g_ptPages = NULL;

void PageRegister(PPageAction ptPageAction)
{
	ptPageAction->ptNext = g_ptPages;
	g_ptPages = ptPageAction;
}

PPageAction Page(char *name)
{
	PPageAction ptTmp = g_ptPages;

	while (ptTmp)
	{
		if (strcmp(name, ptTmp->name) == 0)
			return ptTmp;
		ptTmp = ptTmp->ptNext;
	}

	return NULL;
}


void PagesRegister(void)
{
	extern void MainPageRegister(void);
	MainPageRegister();
}

