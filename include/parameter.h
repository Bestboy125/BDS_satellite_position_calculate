#pragma once
#include <string.h>
using namespace std;
class parameter
{
    public:
	//第一行的参数
		char PRN[20]="initialization";//PRN号
		double year=0;//年 BDT year
		double month = 0;//月
		double day = 0;//日
		double hour = 0;//时
		double min = 0;//分
		double sec = 0;//秒
		double SClockBias = 0;//卫星钟的偏差(s)
		double SClockDri = 0;//卫星钟的漂移(s/s)
		double SClockDriV = 0;//卫星钟的漂移速度(s/s^2)
	//第二行的参数（广播轨道1）
		double AODE = 0;//数据、星历发布时间
		double Crs = 0;//(m) 摄动改正
		double deltan = 0;//(rad/s) 参考时刻卫星平均角速度与计算值之差
		double M0 = 0;//(rad) 平近点角
	//第三行的参数（广播轨道2）
		double Cuc = 0;//(rad) 摄动改正
		double e = 0;//轨道偏心率
		double Cus = 0;//(rad) 摄动改正
		double sqrtA = 0;//(m^0.5) 长半轴
	//第四行的参数（广播轨道3）
		double TOE = 0;//星历的参考时刻（BDS周内的秒数）
		double Cic = 0;//(rad) 摄动改正
		double omega0 = 0;//(rad) 升交点经度
		double Cis = 0;//(rad) 摄动改正
	//第五行的参数（广播轨道4）
		double i0 = 0;//(rad) 轨道倾角
		double Crc = 0;//(m) 摄动改正
		double omega = 0;//(rad) 近地点幅角
		double dOmega = 0;//(rad/s) 升交点赤经变化率
	//第六行的参数（广播轨道5）
		double di = 0;//（IDOT）轨道倾角变化率
		double spare1 = 0;//备用
		double wn = 0;//BDT周数（与TOE一同表示时间）
		double spare2 = 0;//备用
	//第七行的参数（广播轨道6）
		double SatAccur = 0;//卫星精度(m)
		double SatState = 0;//卫星健康状态
		double TGD1 = 0;//B1/B3(sec)
		double TGD2 = 0;//B2/B3(sec)
	//第八行的参数（广播轨道7）
		double SendTime = 0;//电文发送时刻（单位为BDT周的秒，通过交接字（HOW）中的Z计数得出）
		double FitRange = 0;//拟合区间
		double spare3 = 0;//备用
		double spare4 = 0;//备用
	//卫星的位置
		double x = 0;
		double y = 0;
		double z = 0;
	//卫星的总体序号数
		int broadcastnum = 0;
};

class CalendarTime
{
public:
	int year;//年
	int mon;//月
	int day;//日
	int hour;//时
	int min;//分
	double sec;//秒
};
class BDSTime
{
public:
	int wn;//周数
	double tos;//秒数
};
class MJD
{
public:
	int day;//整日期
	double fracDay;//后面的小数
};