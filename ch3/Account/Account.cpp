#include <iostream>
#include "Account.h"

using namespace std;

Account::Account( float amount )
{
    this->amount = amount;
}

void Account::credit( float amount )
{
    if (0 > amount)
    {
        cout << "Invalid amount." << endl;
        return;
    }

    cout << "You have successfully put " << amount << " dollars into your account. " << endl;
    this->amount += amount;
}

void Account::debit( float amount )
{
    if( 0 > this->amount - amount )
    {
        cout << "Account balance not enough." << endl;
        return;
    }

    cout << "You have successfully get out $" << amount << "." << endl;
    this->amount -= amount;
}

float Account::getBalance()
{
    cout << "Your balance is " << this->amount << " dollars." << endl;
    return this->amount;
}
