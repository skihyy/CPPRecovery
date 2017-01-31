#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

void outputVector( const vector<int> );

int main ()
{
    vector<int> v1(10), v2(v1);

    cout<<"After initilization, addresses:"<<setw(15)<<&v1<<setw(15)<<&v2<<endl;
    cout<<"v1 == v2: "<<(v1 == v2)<<endl;

    cout<<"v1 is:"<<endl;
    outputVector(v1);
    cout<<"v2 is:"<<endl;
    outputVector(v1);

    v1[7] = 8;
    v2.at(7) = 8;

    cout<<"After change, addresses:"<<setw(15)<<&v1<<setw(15)<<&v2<<endl;
    cout<<"v1 == v2: "<<(v1 == v2)<<endl;

    cout<<"v1 is:"<<endl;
    outputVector(v1); 
    cout<<"v2 is:"<<endl;
    outputVector(v1);

    v1[8] = 22;

    cout<<"After change, addresses:"<<setw(15)<<&v1<<setw(15)<<&v2<<endl;
    cout<<"v1 == v2: "<<(v1 == v2)<<endl;

    cout<<"v1 is:"<<endl;
    outputVector(v1); 
    cout<<"v2 is:"<<endl;
    outputVector(v1);

    cout<<"Out-of-range changes: v1[10] = 22"<<endl;
    v1[10] = 22; 

    cout<<"v1 is:"<<endl;
    outputVector(v1);

    return 0;
}

void outputVector( const vector<int> v )
{
    cout<<setw(3)<<"No."<<setw(20)<<"Address"<<setw(20)<<"Value"<<endl;
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<<setw(3)<<i<<setw(20)<<&v[i]<<setw(20)<<v[i]<<endl;
    }
    cout<<endl;
}
