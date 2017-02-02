#include<iostream>
#include<iomanip>

using namespace std;

void selectionSort( int *, const int, bool (*)( const int, const int )); // function pointer
void swap(int * const, int * const );
bool ascending(const int, const int);
bool descending(const int, const int);

int main ()
{
    const int arrayLength = 20;
    int a[arrayLength] = {32, 45, 24, 12, 45, 67, 88};

    cout<<setw(13)<<"Original:";
    for(size_t i = 0; i < arrayLength; i++)
    {
        cout<<setw(3)<<a[i];
    }

    cout<<endl<<setw(13)<<"Ascending:";
    selectionSort( a, arrayLength, ascending );
    for(size_t i = 0; i < arrayLength; i++)
    {
        cout<<setw(3)<<a[i];
    }

    cout<<endl<<setw(13)<<"Descending:";
    selectionSort( a, arrayLength, descending );
    for(size_t i = 0; i < arrayLength; i++)
    {
        cout<<setw(3)<<a[i];
    }

    return 0;
}

void selectionSort( int * array, const int size, bool (*compare) (const int, const int))
{
    int index = 0;

    for(size_t i = 0; i < size - 1; i++)
    {
        index = i;

        for(size_t j = i + 1; j < size; j++)
        {
            if(!compare(array[index], array[j]))
            {
                index = j;
            }
        }

        swap( &array[index], &array[i] );
    }
}

void swap(int * const aPtr, int * const bPtr)
{
    int tmp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = tmp;
}

bool ascending(const int a, const int b)
{
    return a < b;
}

bool descending(const int a, const int b)
{
    return a > b;
}
