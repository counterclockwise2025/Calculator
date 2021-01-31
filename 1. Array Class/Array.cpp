// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
#define DEFAULT_MAX_SIZE 100

//default constructor
Array::Array (void)

// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE I placed each of them on it's own lines so that way its easier to catch the error

    // declaring the inital pointer to 0, setting the current size to 0
    // setting the max value to 100 
    : data_(nullptr) 
    , cur_size_(0)
    , max_size_(DEFAULT_MAX_SIZE)
{
    
}

//initializing constructor
Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE I placed each of them on it's own lines so that way its easier to catch the error

    /*
    *first set the data pointer by allocating new memory spot on the heap as base and pass in length as parameter
    *then set the initial size to length since it has already allocated 'said' spots
    *pass in the max size just to have it as member variable
    */
    : data_(new char[length]) 
    , cur_size_(length) 
    , max_size_(length)
{

}

//initializing constructor including fill function
Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE I placed each of them on it's own lines so that way its easier to catch the error

    //similar to the previous constructor but call the fill function to act upon when needed
    : data_(new char[length]) 
    , cur_size_(length) 
    , max_size_(length)
{
    Array::fill(fill);
}

//copy constructor
Array::Array (const Array & array)
    //create new copy of the current array
    : data_(new char[array.cur_size_]) 
    , cur_size_(array.cur_size_) 
    , max_size_(array.max_size_)
{
    //for loop through the array to make a new shallow copy
    for (int i; i < cur_size_; i++)
    {
        data_[i] = array[i];
    }
}

//deconstructor
Array::~Array (void)
{
    //the only dynamically allocated memory was the array, therefore it needs to be removed
    delete [] data_;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const Array & Array::operator = (const Array & rhs)
{
    //if the self does not equal the right hand side
    if (this != &rhs) 
    {
        // COMMENT You should only change the allocation size of this array is not
        // large enough to hold rhs.
        
        // RESPONSE I called the resize function to check the conditions and when resize returns the size then the data will loop and set the rhs equal to
        // to the current size
        
        //checks the conditions through using the resize function
        Array::resize(rhs.size());

        for (int i = 0; i < cur_size_; i++)
        {
            data_[i] = rhs[i];
        }
    }
    //return dereference
    return *this;
}

//get the character at the specificed index
char & Array::operator [] (size_t index)
{
    // COMMENT size_t can never be less than 0

    // RESPONSE removed the check for less than 0

    //instead of calling the get method I had to recopy this from the Array::get() some reaon I kept getting a weird error
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    //return the the value at the specificed index
    return data_[index];
}

//return the unmodifable character
const char & Array::operator [] (size_t index) const
{
    // COMMENT size_t can never be less than 0

    // RESPONSE removed the check for less than 0

    //instead of calling the get method I had to recopy this from the Array::get() some reaon I kept getting a weird error
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    //return the the value at the specificed index
    return data_[index];
}

//get the value
char Array::get (size_t index) const
{
    // COMMENT size_t can never be less than 0

    // RESPONSE removed the check for less than 0

    //if index is greater or equal to the current size then throw the out of range execption
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    //return the the value at the specificed index
    return data_[index];
}

//set the new size
void Array::set (size_t index, char value)
{
    // COMMENT size_t can never be less than 0

    // RESPONSE removed the check for less than 0

    //if index is greater or equal to the current size than throw the out of range execption
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    //set the new value at the index
    data_[index] = value;
}

//resize the array based on the input condition
void Array::resize (size_t new_size)
{
    // COMMENT size_t can never be less than 0

    // COMMENT There is no limit on the max size. If the new size is
    // greater than the max size, then you need to make a large allocation
    // while preserving the current elements in the array.

    // RESPONSE removed the check for less than 0

    // RESPONSE rechange the condition in order to match the required condition. Where it will check for new size vs max size
    // if the new size is less than the current size
    // set everything between the current size and new size to NULL when changing the new size is greater than current size but less than max size

    //checking to make sure the new size is greater than the max size
    if (new_size > max_size_)
    {
        //allocating new memory to pointer variable to store original data
        char * temp = new char [new_size];
        //looping through the max size of the array and copying the data into new size array
        for (int i = 0; i < max_size_; i++)
        {
            temp[i] = data_[i];
        }
        //free memory that is no longer needed
        delete [] data_;
        //assign the pointers back to the same spot
        data_ = temp;
        //set new size to the new max size
        max_size_ = new_size;
        //set the current size to the new size 
        cur_size_ = new_size;
    }

    else
    {
        //if the new size is less than the current the array is shortened to the new size
        if (new_size < cur_size_)
        {
            cur_size_ = new_size;
        }
        //if the new size of the array is greater than the current size, the array is bigger but the new elements are not initialized
        //new size is greater than current size but less than the max size
        else
        {
            for (int i = cur_size_; i < new_size; i++)
            {
                //set the values between current size and new size to zero in order to get rid of garbage data
                data_[i] = 0;
            }
            //set the current size equal to the new size
            cur_size_ = new_size;
        }
    }
}


//find the specificed character in the array
int Array::find (char ch) const
{
    // COMMENT Using find with index is good, but it will throw an exception is certain cases.
    // The find with no index should not throw an exception.

    // RESPONSE changed it to where call is removed for the find function and instead just loops the array without a execption
    // handling condition

    //loop through the array
    for (int i = 0; i < cur_size_; i++)
    {
        //if the array index matches the character than return the index
        if (data_[i] == ch)
        {
            return i;
        }
    }
    //if nothing is found than return -1
    return -1;
}

//find the specificed character with a specific start index
int Array::find (char ch, size_t start) const
{
    // COMMENT size_t can never be less than 0

    // RESPONSE remove the less than condition 

    //if the start is greater or equal to the current size than throw the out of range execption
    if (start >= cur_size_)
    {
        throw std::out_of_range("Cannot start serach index below 0 or greater than your current size.");
    }
    //loop through the array
    for (int i = start; i < cur_size_; i++)
    {
        //if the array index matches the character than return the index
        if (data_[i] == ch)
        {
            return i;
        }
    }
    //if nothing is found than return -1
    return -1;
}


//operator eqauls
bool Array::operator == (const Array & rhs) const
{
    //self compared to the address of the rhs returns true
    if (this == &rhs)
    {
        return true;
    }
    //checking is the current data is the same and if not it will return false
    if (cur_size_ != rhs.cur_size_)  
    {
        return false;
    }
    //looping through the array to compared if each element within is the same, as soon as one is not it returns false
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] != rhs.data_[i])
        {
            return false;
        }
    }
    return true;
}

//operator does not equal
bool Array::operator != (const Array & rhs) const
{
    //compare the self to the rhs and flip its value 
    return !(*this == rhs);
}

//fill the array with ch
void Array::fill (char ch)
{
    //loop through the array of current size and assign it ch for each index
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = ch;
    }
}

void Array::shrink (void)
{
    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation.

    // RESPONSE removed the condition to check for space allocated and just check for current size is less than max size
    // since resize takes care of the rest

    if (cur_size_ > max_size_)
    {
        //allocating more memory to pointer variable to store the original data
        char *temp = new char[cur_size_];
        //loop through the array and copy the old values in the data array into the temp array so we do not lose the old data
        for (int i = 0; i < cur_size_; i++)
        {
            temp[i] = data_[i];
        }
        //free memory used by data original to free space in order to avoid memory leak
        delete[] data_;
        //assign the pointers to the same spot
        data_ = temp;
    }
}

//reverse the array
void Array::reverse (void)
{
    // COMMENT There is no need to create a copy of the array to reverse its contents

    // RESPONSE instead of copying contents over and flipping this flips to it to the midpoint by checking when i
    // is less than j

    //loop through the current size but setting the index to 0 and j to the current size. i increases and j decreases each time
    for (int i = 0, j = cur_size_; i < j; i++, j--)
    {
        //set each value accordingly
        data_[i] = data_[j];
    }
}

//slice the array
Array Array::slice (size_t begin) const
{
    //call slice function and pass in current size and begin as a parameter
    return Array::slice(begin, cur_size_);
}

//slice function
Array Array::slice (size_t begin, size_t end) const
{
    //create another temp array of the end - begin to get the size of new array
    Array temp(end - begin);
    //loop through the array and set the temp value to the the current values based inside the old array set by adding the previous value plus one
    //loop starts at position 0 in memory and sets the temp array to what the index + the begin value is and repeats that to the end
    for (int i = 0; i < end - begin; i++)
    {
        temp.set(i, data_[i + begin]);
    }
    //return the new sliced array
    return temp;
}
