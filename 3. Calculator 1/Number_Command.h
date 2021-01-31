#ifndef _NUMBER_COMMAND_
#define _NUMBER_COMMAND_

#include "Expr_Command.h"

class Number_Command : public Expr_Command
{
    private:
        int stack_num;

    public:
        // Default constructor
        Number_Command(void);
        
        // Constructor
        Number_Command(int number);

        // Destructor
        virtual ~Number_Command(void);

        // Evaluate number
        virtual int evaluate(int number);

        // Execute command
        virtual void execute (Stack<int> & stack);
};

#endif //!defined _NUMBER_COMMAND_
