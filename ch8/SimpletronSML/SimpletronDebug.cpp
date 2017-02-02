#include<iostream>
#include"Simpletron.h"

using namespace std;

int main ( )
{
    Simpletron simpletron;

    int order, pos = 0;

    while ( true )
    {
        cout<<"Test mode, enter order (-1 to quit, 10001 to display details): "<<endl;
        cin>>order;
        if(-1 == order)
        {
            break;
        }
        else if(10001 == order)
        {
            simpletron.displayDetails ();
        }
        else
        {
            simpletron.debug (order, pos++);
        }
    }

    return 0;
}
