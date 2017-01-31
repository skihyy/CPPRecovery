#include <iostream>
#include "GradeBook.h"

using std::cout;
using std::endl;

GradeBook::GradeBook( string name )
{
    this->course = name;
}

void GradeBook::setCourse( string name)
{
    this->course = name;
}

string GradeBook::getCourse()
{
    return this->course;
}

void GradeBook::displayMessage()
{
    cout << "Welcome to the grade book for"
        << endl << this->course << "!" << endl;
}

