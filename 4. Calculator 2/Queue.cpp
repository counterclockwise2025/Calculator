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
    /**
     * Sets the value by checking size and current element
     * then adds on to the rear.
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


//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
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
