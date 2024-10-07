#ifndef SEARCHING_H_
#define SEARCHING_H_
#include "List.h"
#include "Vector.h"

using namespace std;

//visiting every element and check ifnumber looking for
template <typename T>
int linear_search_V(const Vector<T>& vec, const T& target)
{
    for(int i = 0; i < vec.sieze(); i++) {
        if(vec[i] == target)
          return i;
    }

    return -1;
}

//return position where it found 
template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target)
{
    typename List<T>::iterator itr;
    for (itr = lst.begin(); itr != lst.end(); ++itr)
    {
      if(*itr == target)
        return itr;
    }

    return lst.end();
} 
//recursion linear search
template <typename T>
int rec_linear_search_V(int k, const Vector<T>& vec, const T& target)
{
    if(vec.empty() || k >= vec.size())
        return -1;
    if(vec[k] == target)
        return k;
    return rec_linear_search_V(k + 1, vec, target);
}

template <typename T>
typename List<T>::const_iterator rec_linear_search_L(typename List<T>::const_iterator itr, const List<T>& lst, const T& target)
{
    if(lst.empty() || itr == lst.end())
        return lst.end();
    if(*itr == target)
        return itr;
    return rec_linear_search_L(++itr, lst, target);
}

#endif
