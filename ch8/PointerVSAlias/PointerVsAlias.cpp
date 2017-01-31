#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    int a = 13, // a number
        *aPtr = &a, // a pointer
        &b = a; // an alias

    cout<<setw(20)<<"Original"<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl
        <<setw(20)<<"a"<<setw(20)<<&a<<setw(20)<<a<<endl
        <<setw(20)<<"aPtr"<<setw(20)<<aPtr<<setw(20)<<*aPtr<<endl
        <<setw(20)<<"b"<<setw(20)<<&b<<setw(20)<<b<<endl<<endl<<endl;

    a = 15;

    cout<<setw(20)<<"a = 15"<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl
        <<setw(20)<<"a"<<setw(20)<<&a<<setw(20)<<a<<endl
        <<setw(20)<<"aPtr"<<setw(20)<<aPtr<<setw(20)<<*aPtr<<endl                               
        <<setw(20)<<"b"<<setw(20)<<&b<<setw(20)<<b<<endl<<endl<<endl;

    *aPtr = 16;

    cout<<setw(20)<<"*aPtr = 16"<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl
        <<setw(20)<<"a"<<setw(20)<<&a<<setw(20)<<a<<endl
        <<setw(20)<<"aPtr"<<setw(20)<<aPtr<<setw(20)<<*aPtr<<endl                               
        <<setw(20)<<"b"<<setw(20)<<&b<<setw(20)<<b<<endl<<endl<<endl;

    b = 20;

    cout<<setw(20)<<"b = 20"<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl
        <<setw(20)<<"a"<<setw(20)<<&a<<setw(20)<<a<<endl
        <<setw(20)<<"aPtr"<<setw(20)<<aPtr<<setw(20)<<*aPtr<<endl                               
        <<setw(20)<<"b"<<setw(20)<<&b<<setw(20)<<b<<endl;
    return 0;
}
