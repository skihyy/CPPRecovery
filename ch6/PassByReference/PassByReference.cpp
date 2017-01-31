#include<iostream>

using namespace std;

int squareByValue( int );
void squareByReference( int & );

int main()
{
    int x = 2, y = 4;
    
    cout<<"Square by value:"<<endl;
    cout<<"Original x: "<<x<<endl;
    squareByValue(x);
    cout<<"After sqaureByValue( int x ): "<<x<<endl<<endl;

    cout<<"Squre by reference:"<<endl;
    cout<<"Original y: "<<y<<endl;
    squareByReference(y);
    cout<<"After squareByReference( int &y ): "<<y<<endl;

    return 0;
}

int squareByValue( const int a )
{
    return a * a;
}

void squareByReference(int &a)
{
    a *= a;
}
