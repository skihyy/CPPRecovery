#include "Maxmin.h"

template< class T >
MaxMin<T>::MaxMin(){};

template< class T >
T MaxMin<T>::maximum(T t1, T t2, T t3)
{
    if(t1 > t2)
    {
        if(t1 > t3)
        {
            return t1;
        }
        return t3;
    }

    if(t3 < t2)
    {
        return t2;
    }

    return t3;
}

template< class T >
T MaxMin<T>::minimum(T t1, T t2, T t3)
{
    if(t1 > t2)
    {
        if(t2 > t3)
        {
            return t3;
        }
        return t2;
    }

    if(t1 > t3)
    {
        return t3;
    }
    return t1;
}

template class MaxMin<double>;