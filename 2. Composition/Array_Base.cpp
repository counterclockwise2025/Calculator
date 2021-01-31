#include "Array_Base.h"
#include <iostream>
#include <stdexcept>

#define DEFAULT_MAX_SIZE 100

//
// Array_Base default constructor 
//
template <typename T>
Array_Base<T>::Array_Base(void)
    : data_(nullptr)
    , cur_size_(0)
    , max_size_(DEFAULT_MAX_SIZE)
{
}

//
// Array_Base (size_t) initializing constructor
//
template <typename T>
Array_Base<T>::Array_Base(size_t length)
    : data_(new T[length])
    , cur_size_(length)
    , max_size_(length)
{
}

//
// Array_Base (size_t, char) fill constructor
//
template <typename T>
Array_Base<T>::Array_Base(size_t length, T fill)
    : data_(new T[length])
    , cur_size_(length)
    , max_size_(length)
{
    Array_Base::fill(fill);
}

//
// Array_Base (const Array_Base &) copy constructor
//
template <typename T>
Array_Base<T>::Array_Base(const Array_Base &Array_Base)
    : data_(new T[Array_Base.cur_size_])
    , cur_size_(Array_Base.cur_size_)
    , max_size_(Array_Base.max_size_)
{
    for (int i; i < cur_size_; i++)
    {
        data_[i] = Array_Base[i];
    }
}

//
// ~Array_Base destructor
//
template <typename T>
Array_Base<T>::~Array_Base(void)
{
    delete[] data_;
}

//
// operator []
//
template <typename T>
T &Array_Base<T>::operator[](size_t index)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

//
// operator []
//
template <typename T>
const T &Array_Base<T>::operator[](size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

//
// get
//
template <typename T>
T Array_Base<T>::get(size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Array_Base<T>::set(size_t index, T value)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    data_[index] = value;
}


//
// find (T)
//
template <typename T>
int Array_Base<T>::find(T value) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == value)
        {
            return i;
        }
    }
    return -1;
}

//
// find (char, size_t)
//
template <typename T>
int Array_Base<T>::find(T val, size_t start) const
{
    if (start >= cur_size_)
    {
        throw std::out_of_range("Cannot start serach index below 0 or greater than your current size.");
    }

    for (int i = start; i < cur_size_; i++)
    {
        if (data_[i] == val)
        {
            return i;
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base<T>::operator==(const Array_Base &rhs) const
{
    if (this == &rhs)
    {
        return true;
    }

    if (cur_size_ != rhs.cur_size_)
    {
        return false;
    }

    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] != rhs.data_[i])
        {
            return false;
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base<T>::operator!=(const Array_Base &rhs) const
{
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base<T>::fill(T value)
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}

//
// size from inline to get the cur_size
//
template <typename T>
size_t Array_Base<T>::size(void) const
{
    return cur_size_;
}

//
// max_size from inline to get the max_size
//
template <typename T>
size_t Array_Base <T>::max_size(void) const
{
    return max_size_;
}

//
// Print the array elements
// 
template <typename T>
void Array_Base <T>::print_array(void) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        std::cout << Array_Base::data_[i] << ",";
    }

    std::cout << std::endl;
}

