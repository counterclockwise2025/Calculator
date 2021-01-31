// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack<T>::Stack(void)
    // Stack has an array and knows current size
    // Default constructor using Array to create a stack.

// COMMENT There is no need to explicitly call the default constructor of
// an object contained in a class.

// RESPONSE Removed the call to the default constructor.
    : stack_size(0)
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    // Copies over the contents of any other stack to a different one.
    : stack_array(Array<T>(stack.stack_array.size()))
    , stack_size(stack.size())
{
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    // Not needed since nothing is on the heap at the time.
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if (stack_size == stack_array.size())
    {
        stack_array.resize(stack_array.size() * 2); //Double the size if the capacity is reached.
    }
    // Setting the value or stack size to higher value pointer and adding on the new element.
    stack_array.set(stack_size, element);
    stack_size ++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{   
    // Checks for queue being empty and if so throws exception that it cannot be popped further.
    // If not empty then takes/pops on value off.
    if (this->stack_size == 0)
    {
        throw Empty_Exception("Stack is empty and cannot be popped any further.");
    }

    else
    {
        stack_size--;
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack& rhs)
{   
    // Checks if the current reference does not equat to rhs
    // then resize the stack.
    // If it does not then return reference.
    if (this != &rhs)
    {
        this->stack_array.resize(rhs.stack_size);
    }
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //'This' is to reference the stack size object within the current class
    // and setting the location to zero
    this->stack_size = 0;
}

//
//
//
template <typename T>
void Stack <T>::print_stack(void)
{
    //Prints the stack using the array method built in the Array_Base.
    stack_array.print_array();
}

