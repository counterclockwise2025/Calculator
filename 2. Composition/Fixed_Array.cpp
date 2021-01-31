// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void)
    // Call to the Array_Base constructor.
    : Array_Base <T> (N)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr)
    // Call to the copy constructor.
    : Array_Base<T>((Array_Base<T>)arr)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill)
    // Call to the fill constructor.
    : Array_Base<T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    // Not in use.
}

/**
 * operator =
 * 
 * This is a class specific method that will compare rhs and returns reference to self. 
 * BUT cannot resize since this is a fixed array.
 */
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < Array_Base<T>::cur_size_; i++)
        {
            Array_Base<T>::data_[i] = rhs[i];
        }
    }
    return *this;
}

