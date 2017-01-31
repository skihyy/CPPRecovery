#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account myAccount(45.3);
    myAccount.getBalance();
    myAccount.credit(-20.4);
    myAccount.debit(48.5); 
    myAccount.getBalance();
    myAccount.debit(32.32);
    myAccount.getBalance();
    myAccount.credit(102.21);
    myAccount.getBalance();

    return 0;
}
