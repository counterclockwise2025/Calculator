#ifndef _EXPR_COMMAND_ITERATOR_
#define _EXPR_COMMAND_ITERATOR_

#include "Array.h"

// Create a new template class for the iterator based on the example in class.
// Using the iterator pattern here.
template <typename T>
class Expr_Command_Iterator
{
    private:
        Array<T> expr_array;
        int current_position;
        size_t max_size_;

    public:
        typedef T type;

        // Default constrcutor
        Expr_Command_Iterator(void);

        // Constructor
        Expr_Command_Iterator(Array<T>& e, int postfix_position);

        // Destructor
        ~Expr_Command_Iterator(void);

        // Keep moving in the array
        void advance(void);

        // Checks if reached the end of the array
        bool is_done(void);

        // * operator
        T operator * (void);

        // -> operator
        T *operator -> (void);
};

#include "Expr_Command_Iterator.cpp"

#endif //!defined _EXPR_COMMAND_ITERATOR_
