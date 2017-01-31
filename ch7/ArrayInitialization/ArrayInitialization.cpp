#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int a[13];

    cout<<setw(5)<<"NO."<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl;

    for(int i = 0; i < 13; i++)
    {
        cout<<setw(5)<<i<<setw(20)<<&a[i]<<setw(20)<<a[i]<<endl;
    }

    int b[13] = {0};
    cout<<endl<<setw(5)<<"NO."<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl;

    for(int i = 0; i < 13; i++)
    {
        cout<<setw(5)<<i<<setw(20)<<&b[i]<<setw(20)<<b[i]<<endl; 
    }

    return 0;
}
