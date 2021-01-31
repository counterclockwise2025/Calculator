//
// size
//
template <typename T>
inline size_t Queue<T>::size(void) const
{   
    // Returns queue size.
    return queue_size;
}

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{   
    // Checks if queue is 0 then returns true,
    // If not then it returns false.
    if (this->queue_size == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

