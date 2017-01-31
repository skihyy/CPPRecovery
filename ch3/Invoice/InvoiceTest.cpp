#include<iostream>
#include<string>
#include"Invoice.h"

using namespace std;

int main()
{
    Invoice invoice("huweidhewn", "Tire 3", 45, -2);
    cout<<invoice.getAmount()<<endl;

    Invoice invoice2("ddww221dwqd", "Tire 5", -22, 93);
    cout<<invoice2.getAmount()<<endl;

    Invoice invoice3("e21xs2de2", "Tire 4", 23, 87);
    cout<<invoice3.getAmount()<<endl;
}
