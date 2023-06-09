#include <iostream>
#include "parameter.h"
using namespace std;

//æ ¼åé«åè½?åä¸ºåç¥æ?
MJD CalendarTime2MJD(CalendarTime calT)
{
	MJD mjd;
	int y, m;
	if (calT.mon <= 2)
	{
		y = calT.year - 1;
		m = calT.mon + 12;
	}
	else
	{
		y = calT.year;
		m = calT.mon;
	}
	//åé¢çæ´æ°å¤©
	mjd.day = (int)((int)(365.25*y) + (int)(30.6001*((double)m + 1)) + calT.day + calT.hour / 24 + 1720981.5 - 2400000.5);
	//æå¤©åé¢çæ¶åç?ä¹åä¸ºå¤?
	mjd.fracDay = 1.0*calT.hour / 24 + 1.0*calT.min / 24 / 60 + calT.sec / 24 / 3600;
	return mjd;
}

//åç¥æ¥è½¬åä¸ºBDSæ?
BDSTime MJD2BDSTime(MJD mjd)
{
	BDSTime bdst;
	bdst.wn = (mjd.day - 44244) / 7;
	bdst.tos = (mjd.day + mjd.fracDay - 44244 - (double)bdst.wn * 7) * 86400;
	return bdst;
}