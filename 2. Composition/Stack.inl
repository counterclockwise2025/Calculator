// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return stack_size;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{   
    // Check stack and looks for the total size and returns that.
    return stack_array.get(this->stack_size);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{   
    // Checks if statck is 0 then returns true.
    // If not then returns false.
    if (this->stack_size == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

