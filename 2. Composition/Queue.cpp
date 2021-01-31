/**
 * Queue
 * 
 * Default constructor
 */
template <typename T>
Queue<T>::Queue(void)
    /**
     * Queue has an array, using the instantiated objects
     * front of queue, rear/back of queue, and the size of the queue
     * Which have all be initialized to 0
     */
// COMMENT There is no need to explicitly call the default constructor of
// an object contained in a class.

// RESPONSE Removed the call to the default constructor.

    : queue_front(0)    
    , queue_rear(0)
    , queue_size(0)
{
}

/**
 * Queue
 * 
 * Copy constructor
 */
template <typename T>
Queue <T>::Queue (const Queue & queue)
    : queue_array(Array<T>(queue.queue_array.size()))
    , queue_front(queue.size())
    , queue_rear(queue.size())
    , queue_size(queue.size())
{
}

// COMMENT Your destructor signature is incorrect.

//RESPONSE Added the "~" that I had forgot.

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    // Not needed at this time since nothing is on the heap
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT The queue will fail if the array runs out of space. Since this
    // is an unboudned queue, you need to resize the array to make space for
    // new elements. Also, make sure you do not waste any space if you must
    // resize the array to accommodate new elements. This will require updates
    // to your dequeue method.

    /**RESPONSE I took into account what you mentioned. Here I went ahead and created multiple cases.
     * This initally checks for the when the queue is full and when the queue does fill up, a new array double it size is created.
     * Then the values are copied over in that order as long as the front value is less than the rear. Meaning its in order.
     * The other accounts for when front value is greatr than the rear meaning that the array has been filled over from spots
     * previously left behind. This basically does the same thing but the new array that is made will have an seperate index
     * so that it able to copy the same values in each index location over. Then after copies the rear values over that 
     * are left behind into the correct locations.
     **/

    /**
     * Sets the value by checking size and current element
     * then adds on to the rear.
     * 
     * 
     */


    if (queue_size == queue_array.size())
    {
        Array<T>tmp(queue_array.size() * 2);

        if (queue_front < queue_rear)
        {
            for(int i = 0; i < queue_array.size(); i++)
            {
                tmp[i] = queue_array[i];
            }
        }

        else
        {
            int index = 0;
            for(int i = queue_front; i < queue_array.size(); i++)
            {
                tmp[index] = queue_array[i];
                index++;
            }

            for(int i = 0; i < queue_rear; i++)
            {
                tmp[index] = queue_array[i];
                index++;
            }
        }

       queue_front = 0;
       queue_rear = queue_size - 1; 
       queue_array = tmp;
    }

    queue_rear = (queue_rear + 1) % queue_array.size();
    queue_array.set(queue_rear, element);
    queue_size ++;
}

// COMMENT I think your return value type is incorrect.

//
// dequeue
//
template <typename T>
void Queue <T>::dequeue (void)
{
    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.

    //RESPONSE Now using spaces to the left using a circular queue implementation.
    
    /**
     * Checks if queue size is 0 or empty and if empty it will throw an expection
     * through the Empty_Exception.
     * Sets the value by checking size and current element.
     * Then removes from the front. 
     */
    if (this->queue_size == 0)
    {
        throw Empty_Exception("Queue is empty and cannot dequeue any further.");
    }

    else
    {
        queue_front = (queue_front + 1) % queue_array.size();
        queue_size --;
    }   
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{   
    // Clears the queue by setting each object back to 0.
    this->queue_size = 0;
    this->queue_front = 0;
    this->queue_rear = 0;
}

//
// Print queue
//
template <typename T>
void Queue <T>::print_queue(void)
{
    // Print the queue using the Array_Base method
    queue_array.print_array();
}

