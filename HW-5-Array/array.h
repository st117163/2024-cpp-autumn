#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstddef>

template <class T, size_t size> 
class Array
{
    T array[size];
  public:
    Array() {};
    Array(T* b);
    void show();
    T minimum(Array<T, size>& m);
};

template<class T, size_t size>
inline Array<T,size>::Array(T* b)
{
	for (size_t i = 0; i < size; ++i)
        {
            array[i] = b[i];
        }
}

template<class T, size_t size>
void Array<T, size>::show()
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<class T, size_t size>
T Array<T, size>::minimum(Array<T, size>& m)
{
	T tmp = m.array[0];
	for (size_t i = 1; i < size; ++i)
	{
		tmp = (m.array[i] < tmp ? m.array[i] : tmp);
	}
	return tmp;
}

#endif