#ifndef _MULTIPLY_COMMAND_
#define _MULTIPLY_COMMAND_

#include "BinaryOp_Command.h"

class Multiply_Command : public BinaryOp_Command
{
    public:
        // Default constructor
        Multiply_Command(void);

        // Destructor
        virtual ~Multiply_Command(void);

        // Evaluate addition operation
        virtual int evaluate(int n1, int n2);

        // Priorty of the operation, (PE)MDEAS
        int priority(void);
};

#endif //!defined _MULTIPLY_COMMAND_
