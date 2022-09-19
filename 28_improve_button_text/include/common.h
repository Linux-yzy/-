

#ifndef _COMMON_H
#define _COMMON_H


typedef struct Region {
	int iLeftUpX;
	int iLeftUpY;
	int iWidth;
	int iHeigh;
}Region, *PRegion;

/*笛卡尔坐标系*/
typedef struct RegionCartesian {
	int iLeftUpX;
	int iLeftUpY;
	int iWidth;
	int iHeigh;
}RegionCartesian, *PRegionCartesian;

#endif

