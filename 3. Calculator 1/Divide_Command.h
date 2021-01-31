#ifndef _DIVIDE_COMMAND_
#define _DIVIDE_COMMAND_

#include "BinaryOp_Command.h"

class Divide_Command : public BinaryOp_Command
{
    public:
        // Default constructor
        Divide_Command(void);

        // Destructor
        virtual ~Divide_Command(void);

        // Evaluate addition operation
        virtual int evaluate(int n1, int n2);

        // Priorty of the operation, (PE)MDEAS
        int priority(void);
};

#endif //!defined _DIVIDE_COMMAND_
