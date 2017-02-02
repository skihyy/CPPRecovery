#include<iostream>
#include"Simpletron.h"

using namespace std;

int main ( )
{
    Simpletron simpletron;

    int order;
    const int size = 1;
    int orders[1];

    while ( true )
    {
        cout<<"Test mode, enter order (-1 to quit): ";
        cin>>order;
        if(-1 == order)
        {
            break;
        }
        orders[0] = order;
        simpletron.takeProgram (orders, size);
        //simpletron.displayDetails ();
    }

    return 0;
}
