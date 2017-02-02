#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include"Simpletron.h"

using namespace std;

Simpletron::Simpletron ( )
{
    this->cleanAll ( );
}

bool Simpletron::cleanAll ( )
{
    for ( size_t i = 0; i < this->rowSize; i++ )
    {
        for ( size_t j = 0; j < this->colSize; j++ )
        {
            this->registers[ i ][ j ] = 0;
        }
    }

    this->addMachine = 0;
}

bool Simpletron::takeProgram ( const int *orders, const int size )
{
    if ( 0 >= size || 100 < size )
    {
        cout << "Error: invalid order length." << endl;
        return false;
    }

    int tmp_order;
    for ( size_t i = 0; i < size; i++ )
    {
        tmp_order = orders[ i ];
        this->storeOneOrder ( tmp_order, i );
    }

    return this->startProgram ( );
}

void Simpletron::storeOneOrder ( int order, const int pos )
{
    if ( order >= 0 )
    {
        if ( 10000 < order )
        {
            cout << "Warning: too long order in " << order << ", only last 5 digits will be received." << endl;
            order %= 10000;
        }
        registers[ pos ][ 0 ] = 1; // 1 -> positive
    }
    else
    {
        if ( -10000 < order )
        {
            cout << "Warning: too long order in " << order << ", only last 5 digits will be received." << endl;
            order %= 10000;
        }
        order *= -1;
        registers[ pos ][ 0 ] = 0; // 0 -> negative
    }
    registers[ pos ][ 2 ] = order % 100;
    order /= 100;
    registers[ pos ][ 1 ] = order;
}

bool Simpletron::startProgram ( )
{
    int cmd, pos;
    for ( size_t i = 0; i < this->rowSize; i++ )
    {
        if ( 1 == this->registers[ i ][ 0 ] )
        {
            cmd = this->registers[ i ][ 1 ];
            pos = this->registers[ i ][ 2 ];
            if ( !takeCmd ( cmd, pos ) )
            {
                cout << "Warning: failed to run command at position " << setw ( 2 ) << setfill ( '0' ) << i << ": \"+"
                     << setw ( 2 ) << setfill ( '0' ) << cmd << setw ( 2 ) << setfill ( '0' ) << pos << "\"" << endl;
            }
        }
    }
    return true;
}

void Simpletron::displayDetails ( )
{
    cout << setw ( 20 ) << "Current add machine: " << this->addMachine << endl << "Memory: " << endl;

    // table header
    cout << setw ( 2 ) << setfill ( ' ' ) << " ";
    for ( int i = 0; i < 10; i++ )
    {
        cout << setw ( 6 ) << i;
    }
    cout << endl;

    for ( size_t i = 0; i < this->rowSize; i++ )
    {
        if ( 0 == i % 10 )
        {
            cout << setw ( 2 ) << i;
        }

        cout << setw ( 1 ) << " " << setw ( 1 ) << ( 1 == this->registers[ i ][ 0 ] ? "+" : "-" ) << setw ( 2 )
             << setfill ( '0' ) << this->registers[ i ][ 1 ] << setw ( 2 ) << setfill ( '0' )
             << this->registers[ i ][ 2 ];

        if ( 9 == i % 10 )
        {
            cout << endl;
        }
    }
}

bool Simpletron::debug ( const int order, const int pos )
{
    this->storeOneOrder ( order, pos );
    return this->takeCmd ( this->registers[ pos ][ 1 ], this->registers[ pos ][ 2 ] );
}

bool Simpletron::takeCmd ( const int cmd, const int pos )
{
    //cout << "Test mode, cmd: " << cmd << ", pos: " << pos << endl;
    switch ( cmd )
    {
        case Simpletron::READ:
            return this->read ( pos );
        case Simpletron::WRITE:
            return this->write ( pos );
        case Simpletron::LOAD:
            return this->load ( pos );
        case Simpletron::STORE:
            return this->store ( pos );
        case Simpletron::ADD:
            return this->add ( pos );
        case Simpletron::SUBSTRACT:
            return this->substract ( pos );
        case Simpletron::DEVIDE:
            return this->devide ( pos );
        case Simpletron::MULTIPLY:
            return this->multiply ( pos );
        case Simpletron::BRANCH:
            return this->branch ( pos );
        case Simpletron::BRANCHNEG:
            return this->branchNeg ( pos );
        case Simpletron::BRANCHZERO:
            return this->branchZero ( pos );
        case Simpletron::HALT: // end of the program
            return true;
        default:
            return false;
    }
}

bool Simpletron::read ( const int pos )
{
    cout << "Enter a number into the register ";

    if ( 10 > pos )
    {
        cout << 0;
    }
    cout << pos << "." << endl << "If longer than 5 characters, only the first 5 will be received: " << endl;
    int num;
    cin.clear ( ); // clear failure state flags on cin
    //cin.ignore ( std::numeric_limits < std::streamsize >::max ( ), '\n' );
    cin >> num;

    // put into registers
    if ( 0 <= num )
    {
        this->registers[ pos ][ 0 ] = 1;
    }
    else
    {
        this->registers[ pos ][ 0 ] = 0;
        num *= -1;
    }
    this->registers[ pos ][ 2 ] = num % 100;
    num /= 100;
    this->registers[ pos ][ 1 ] = num;
    return true;
}

bool Simpletron::write ( const int pos )
{
    cout << "Register at " << setw ( 2 ) << pos << setw ( 3 ) <<
         ": " << ( 1 == this->registers[ pos ][ 0 ] ? "+" : "-" );
    if ( 10 > this->registers[ pos ][ 1 ] )
    {
        cout << 0;
    }
    cout << this->registers[ pos ][ 1 ];
    if ( 10 > this->registers[ pos ][ 2 ] )
    {
        cout << 0;
    }
    cout << this->registers[ pos ][ 2 ] << endl;
    return true;
}

bool Simpletron::load ( const int pos )
{
    int tmp = this->registers[ pos ][ 1 ] * 100 + this->registers[ pos ][ 2 ];
    if ( 0 == this->registers[ pos ][ 0 ] )
    {
        tmp *= -1;
    }
    this->addMachine = tmp;
    return true;
}

bool Simpletron::store ( const int pos )
{
    int tmp = this->addMachine;
    if ( 0 <= addMachine )
    {
        this->registers[ pos ][ 0 ] = 1;
    }
    else
    {
        this->registers[ pos ][ 0 ] = 0;
        tmp *= -1;
    }

    this->registers[ pos ][ 1 ] = tmp / 100;
    this->registers[ pos ][ 2 ] = tmp % 100;

    return true;
}

bool Simpletron::add ( const int pos )
{
    int tmp = this->addMachine;
    this->load ( pos );
    this->addMachine += tmp;
    return true;
}

bool Simpletron::substract ( const int pos )
{
    int tmp = this->addMachine;
    this->load ( pos );
    this->addMachine = tmp - this->addMachine;
    return true;
}

bool Simpletron::multiply ( const int pos )
{
    int tmp = this->addMachine;
    this->load ( pos );
    this->addMachine *= tmp;
    return true;
}

bool Simpletron::devide ( const int pos )
{
    int tmp = this->addMachine;
    this->load ( pos );
    this->addMachine *= tmp / this->addMachine;
    return true;
}

bool Simpletron::branch ( const int pos )
{
    return this->store ( pos );
}

bool Simpletron::branchNeg ( const int pos )
{
    if ( 0 > this->addMachine )
    {
        return this->branch ( pos );
    }
    return false;
}

bool Simpletron::branchZero ( const int pos )
{
    if ( 0 == this->addMachine )
    {
        return this->branch ( pos );
    }
    return false;
}