#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

void outputVector( const vector<int> & );
void inputVector( vector<int> & );

int main ()
{
    vector<int> v1( 7 ), v2( 10 );

    cout<<"Size of v1: "<<v1.size()<<endl
        <<"Size of ve: "<<v2.size()<<endl<<endl;

    outputVector( v1 );
    outputVector( v2 );

    cout<<"Enter 17 integers: "<<endl;
    inputVector( v1 );
    inputVector( v2 );

    cout<<endl<<"After input, the vectors contain:"<<endl;

    outputVector( v1 );
    outputVector( v2 );

    cout<<"Evaluating v1 != v2: "<<(v1 != v2)<<endl<<endl;

    vector<int> v3( v1 );

    cout<<"Size of v3: "<<v3.size()<<endl<<endl;

    cout<<"Evaluating v1 == v3: "<<(v1 == v3)<<endl<<endl;

    outputVector( v3 );

    cout<<"Assigning v2 to v1 (v1 larger than v2):"<<endl;
    v1 = v2;

    cout<<"The vectors contain:"<<endl;
    outputVector( v1 );
    outputVector( v2 );

    cout<<"Evaluating v1 != v2: "<<(v1 != v2)<<endl<<endl;

    cout<<"v1[5]: "<<v1[5]<<endl<<endl;

    cout<<"Attempt to assign 1000 to v1 at 15 (out-of-range):"<<endl;
    v1.at( 15 ) = 1000;

    return 0;
}

void outputVector( const vector<int> &v )
{
    cout<<"Vector: "<<endl;

    size_t i;
    for(i = 0; i < v.size(); i++)
    {
        cout<<setw(12)<<v[i];
        if(0 == (i + 1) % 4)
        {
            cout<<endl;
        }
    }

    if(0 != i % 4)
    {
        cout<<endl;
    }
    cout<<endl;
}

void inputVector( vector<int> &v )
{
    for(size_t i = 0; i < v.size(); i++ )
    {
        cin >> v[i];
    }
}
