#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <string>
#include "parameter.h"
#include "statement.h"

using namespace std;

int main(){

    //定义星历对象数组,存储星历信息
    parameter s[1329];

    //定义文件位置
    string satellite_ephemeris_filename="/home/bob/Desktop/navigation system lesson/assignment/assignment 2/data/brdm0020.20p";
    string satellite_position_filename="/home/bob/Desktop/navigation system lesson/assignment/assignment 2/data/position";

    //读取星历文件
    readeph(s, satellite_ephemeris_filename);

    //设计一个函数使得输入星历文件，得到位置文件
    C01_position(s, satellite_position_filename);//GEO-8
    C02_position(s, satellite_position_filename);//GEO-6
    C07_position(s, satellite_position_filename);//IGSO-2
    C08_position(s, satellite_position_filename);//IGSO-3
    C21_position(s, satellite_position_filename);//MEO-3
    C20_position(s, satellite_position_filename);//MEO-2
    return 0;
}   