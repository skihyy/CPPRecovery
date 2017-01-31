#include<iostream>
#include"Invoice.h"

using namespace std;

Invoice::Invoice(string seriesNo, string description, int numOfSold, int price)
{
    setSeriesNo(seriesNo);
    setDescription(description);
    setPrice(price);
    setNumOfSold(numOfSold);
}

int Invoice::getAmount()
{
    return getPrice() * getNumOfSold();
}

void Invoice::setSeriesNo(string  no)
{
    seriesNo = no;
}

string Invoice::getSeriesNo()
{
    return seriesNo;
}

void Invoice::setDescription(string des)
{
    description = des;
}

string Invoice::getDescription()
{
    return description;
}

void Invoice::setNumOfSold(int sold)
{
    if(0 > sold)
    {
        sold = 0;
    }
    numOfSold = sold;
}

int Invoice::getNumOfSold()
{
    return numOfSold;
}

void Invoice::setPrice(int p)
{
    if(0 > p)
    {
        p = 0;
    }
    price = p;
}

int Invoice::getPrice()
{
    return price;
}
