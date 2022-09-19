/**
 * @file config.h
 * @brief 
 * @version
 * @copyright Copyright (c) 2022
 * @history:
 * Date                         Author      Version    Description
 * 2022-09-18 09-39-04          Byron
 */
#ifndef _CONFIG_H
#define _CONFIG_H

#define ITEMCFG_MAX_NUM 30
#define CFG_FILE  "/etc/test_gui/gui.conf"

typedef struct ItemCfg {
	int index;
	char name[100];
	int bCanBeTouched;
	char command[100];
}ItemCfg, *PItemCfg;

int ParseConfigFile(void);
int GetItemCfgCount(void);
PItemCfg GetItemCfgByIndex(int index);
PItemCfg GetItemCfgByName(char *name);


#endif

