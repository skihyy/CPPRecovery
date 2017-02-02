//
// Created by Yuyang He on 2017/2/2.
//
#include<iostream>
#include"Simpletron.h"

using namespace std;

int main ( )
{
    int orders[9] = { 1009, 1010, 2009, 3110, 4107, 1109, 4300, 1110, 4300 };

    Simpletron simpletron;
    simpletron.takeProgram ( orders, 9 );
    simpletron.displayDetails ( );

    return 0;
}

