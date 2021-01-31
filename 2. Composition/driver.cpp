#include "Array.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include "Stack.h"


int main(int argc, char *argv[])
{
    /**
     * Test Fixed array
     */
        //Set a size of the array and fill it. And make sure it can't resize.

        /*
        Fixed_Array<int, 10> test_fixed = Fixed_Array<int, 10>();
        test_fixed.set(0, 5);
        test_fixed.print_array();
        
    /**
     * Test Array
     */
        // Make the array resize itself
        /*
        Array<int> test_array = Array<int>();
        test_array.fill(20);
        test_array.print_array();
        test_array.resize(50);
        test_array.print_array();

    /**
     * Test Queue
     */
        //Fill Queue to max and then resize itself

    /**
     * Test Stack
     */
        //Test operator equals and push pop on stack to see if it will work for the calculator
}

