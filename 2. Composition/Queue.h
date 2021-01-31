#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include "Empty_Exception.h"

/**
 * @class Queue
 * 
 * Basic queue for abitrary elements
 */

template <typename T>
class Queue
{
    public:
        // Type defintion of the type
        typedef T type;

        // Default constructor
        Queue (void);

        // Copy constructor 
        Queue (const Queue & queue);

        // Destructor 
        ~Queue (void);

        /**
         * Adds the element to the end of the list
         * or queue.
         */
        void enqueue (T element);

        /**
         * Removes the element at the front of the list.
         * If there are not elements in the queue, this method throws
         * empty_exception.
         */
        void dequeue (void);

        /**
         * Test if the queue is empty
         *
         * @retval         true          The queue is empty
         * @retval         false         The queue is not empty
         */
        bool is_empty(void) const;

        /**
         * Number of element on the queue.
         *
         * @return         Size of the queue.
         */
        size_t size(void) const;

        /// Remove all elements from the queue.
        void clear(void);

        // Print queue
        void print_queue(void);
        
    private:
        // add member variable here
        Array<T> queue_array;
        size_t queue_front;
        size_t queue_rear;
        size_t queue_size;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif // !defined _CS507_STACK_H_

