// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"


//
// Array
//
template <typename T>
Array<T>::Array(void)
    // Call to the Array_Base constructor.
    : Array_Base <T> ()
{
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length)
    // Call to Array_Base initialzing constructor.
    : Array_Base<T>(length)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill)
    // Call to the fill constructor.
    : Array_Base <T> (length, fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array &array)
    // Call to the copy constructor.
    : Array_Base <T> (array)
{
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    // Desctructor to get rid of array off the heap.
    delete[] Array_Base<T>::data_;
}

/**
 * operator =
 * 
 * This is a class specific method and was not inherited because 
 * I noticed that the array will need to resize if 'operator =' is called. 
 * This method will compare rhs, resize, and returns reference to self. 
 */
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (this != &rhs)
    {
        Array::resize(rhs.size());

        for (int i = 0; i < Array_Base<T>::cur_size_; i++)
        {
            Array_Base<T>::data_[i] = rhs[i];
        }
    }
    return *this;
}

/** 
 * Resize
 * 
 * This method cannot be inheirited by the Fixed_Array since that would not make sense at all. The point of the Fixed_Array
 * is to stay the same, therefore it cannot resize. So this method is only for array since it
 * needs to be able to resize itself.
 */
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size > Array_Base<T>::max_size_)
    {
        T *temp = new T[new_size];

        for (int i = 0; i < Array_Base<T>::max_size_; i++)
        {
            temp[i] = Array_Base<T>::data_[i];
        }

        delete[] Array_Base<T>::data_;
        Array_Base<T>::data_ = temp;
        Array_Base<T>::max_size_ = new_size;
        Array_Base<T>::cur_size_ = new_size;
    }

    else
    {
        if (new_size < Array_Base<T>::cur_size_)
        {
            Array_Base<T>::cur_size_ = new_size;
        }

        else
        {
            for (int i = Array_Base<T>::cur_size_; i < new_size; i++)
            {
                Array_Base<T>::data_[i] = 0;
            }

            Array_Base<T>::cur_size_ = new_size;
        }
    }
}
