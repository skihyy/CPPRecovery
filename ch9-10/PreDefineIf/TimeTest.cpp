#include<iostream>
#include"Time.h"

using namespace std;

int main()
{
    Time t;

    t.setTime(13, 27, 6);
    t.printUniversal();
    t.printStandard();

    t.setTime(99, 99, 99);
    t.printStandard();

    return 0;
}
