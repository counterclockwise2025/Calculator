#ifndef _BINARYOP_COMMAND_
#define _BINARYOP_COMMAND_

#include "Expr_Command.h"

class BinaryOp_Command : public Expr_Command
{
    public:
        // Default constructor
        BinaryOp_Command (void);

        // Destructor
        virtual ~BinaryOp_Command (void);

        // Evaluate case handler
        virtual int evaluate (int n1, int n2) = 0;

        // Execute command
        virtual void execute(Stack<int> & stack);
};

#endif //!defined _BINARYOP_COMMAND_
