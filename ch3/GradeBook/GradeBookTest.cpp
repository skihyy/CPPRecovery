#include <iostream>
#include "GradeBook.h"

using std::cout;
using std::endl;

int main()
{
    GradeBook gradebook( "CS 101 Introduction to C++ Programming" );
    gradebook.displayMessage();

    return 0;
}
