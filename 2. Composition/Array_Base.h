#ifndef _ARRAY_BASE_
#define _ARRAY_BASE_

#include <cstring>          // for size_t definition 

template <typename T>
class Array_Base
{   
    protected:
        // Pointer to real data.
        char *data_;

        // Current size of array.
        size_t cur_size_;

        // Max size of array.
        size_t max_size_;

    public:
        /// Type definition of the element type.
        typedef T type;

        // Default Constructor
        Array_Base(void);

        // Copy Constructor
        Array_Base(const Array_Base & arr);

        // Initializing constructor
        Array_Base(size_t length);

        // Initializing fill
        Array_Base(size_t length, T fill);

        // Destructor
        ~Array_Base(void);

        // Retrieve current size of the array.
        size_t size(void) const;

        // Retrieve the maximum size of the array.
        size_t max_size(void) const;

        // Get character at specificed index. If not in range, throw execption.
        T &operator[](size_t index);

        // Returned character is not modifiable.
        const T &operator[](size_t index) const;

        // Get character at specificed index. If not in range, throw execption.
        T get(size_t index) const;

        // Set character at specificed index. If not in range, throw execption.
        void set(size_t index, T value);

        // Find specificed character at an index. If not found then return -1.
        int find(T element) const;

        // Find specificed character at an index with a start point. If not found then return -1.
        int find(T element, size_t start) const;

        // Test for array equality.
        bool operator==(const Array_Base &rhs) const;

        // Test for array inequality.
        bool operator!=(const Array_Base &rhs) const;

        // Fill the array with content.
        void fill(T element);

        // Print all elements in array
        void print_array(void) const;
};

#include "Array_Base.cpp"

#endif // !defined _Array_Base_

