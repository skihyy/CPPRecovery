#include<iostream>

using namespace std;

int main()
{
    int x = 3;
    int &y = x; // alias

    cout<<"Address of x: "<<&x<<endl;
    cout<<"Address of y: "<<&y<<endl<<endl;

    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;

    y = 7;

    cout<<"Address of x: "<<&x<<endl;          
    cout<<"Address of y: "<<&y<<endl<<endl;

    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl; 

    return 0;
}
