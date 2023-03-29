# BDS_satellite_position_calculate
#说明

#致谢：

1.https://github.com/hjd-whu/Satellite-position-calculation

2.https://github.com/KaramMawas/Navigation1

# 卫星星历计算BDS卫星位置

# 前言

导航课的第二次大作业，任务是批量计算一天的BDS卫星的位置。

# 参考资料

1. [https://github.com/hjd-whu/Satellite-position-calculation](https://github.com/hjd-whu/Satellite-position-calculation)

武汉大学，老牌测绘强校，学生素质强！

# 过程记录

## 星历数据下载

1. [https://www.epncb.oma.be/ftp/obs/](https://www.epncb.oma.be/ftp/obs/BRDC/2023/)
2. GitHub数据下载工具：https://github.com/ChangChuntao/FAST

## 星历数据说明

1. [http://acc.igs.org/misc/rinex304.pdf](http://acc.igs.org/misc/rinex304.pdf)

## 卫星编号说明

1. [http://www.csno-tarc.cn/en/system/constellation](http://www.csno-tarc.cn/en/system/constellation)

## 参数定义

### 科学计数法

x.xxxxxex

一般是浮点数

```cpp
double scinum=1.3343e10;
```

### 定义常量

```cpp
constant double scinum=1.333e14;
```

## 主函数

输入：星历文件(readeph)

输出：各时间节点的卫星位置(positon)

定义星历存放数组

定义文件位置的字符串

## 参数定义

1. BRDS中数据当中没有 BDS特有的参数，数据说明表中也没有，这可能是测站解算后的数据

## 文件流读取数据+筛选数据

1. 筛选原则：
    1. 根据首字母’C’ ‘G’等来区分卫星
    2. 根据行数的余数确定参数位置
    3. 每8行一个周期

## 文件流输出数据

首先，第一点，因为要绘制卫星的三维轨道图，仅凭卫星的观测的12或者24个值不足以确定卫星的轨道。因此，这里提出一种时间间隔为15分钟的增加点数的算法。每一个15分钟节点的卫星星历使用与其最接近的观测时间的卫星星历。这样会每个卫星便有了96个轨道点。

其次，使用文件流输出，输出一个卫星位置的txt文件，便于后续的绘制

## 卫星位置计算函数

按照公式一步步写入即可

## 时间转换系统

北斗时转换成儒略日

北斗时的周内秒等于BDS时的周内秒

所以可以直接用GPS解算出来的周内秒

# 可视化解算成果

## 二维图像（经纬度与X，Y的关系）

## 三维图像

1. 地固坐标系
2. 天球坐标系

# 经验总结

## 中文乱码

情景：Windows下编写的.cpp文件 在Linux环境 g++编译输出出现中文乱码。

解决办法：Windows下用记事本打开.cpp文件，另存为UTF-8 BOOM编码格式，即可解决

## vscode编译问题

情景：多文件编译，有头文件和源文件，小型工程

解决办法：vscode的 task.json文件 “{file}”后加上额外的.cpp文件

缺陷：文件多了之后会很麻烦

更优的解决办法：CMakeList.txt 跨平台

简洁的解决办法：IDE编译平台，例如visual studio 2022，dev c++
