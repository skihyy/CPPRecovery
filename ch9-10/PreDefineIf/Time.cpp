#include<iostream>
#include<iomanip>
#include"Time.h"

using namespace std;

Time::Time()
{
    hour = second = minute = 0;
}

void Time::setTime(int h, int m, int s)
{
    this->hour = (0 <= h && 23 >= h) ? h : 0;;
    this->minute = (0 <= m && 59 >= m) ? m : 0;
    this->second = (0 <= s && 59 >= s) ? s : 0;
}

void Time::printUniversal()
{
    cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second<<endl;
}

void Time::printStandard()
{
    cout<<setfill('0')<<setw(2)<<((0 == hour || 12 == hour) ? 12 : hour % 12)
        <<":"<<setw(2)<<minute<<":"<<setw(2)<<second<<" "<<(12 < hour ? "AM" : "PM")<<endl;
}
