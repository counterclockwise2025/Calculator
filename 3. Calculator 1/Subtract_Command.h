#ifndef _SUBTRACT_COMMAND_
#define _SUBTRACT_COMMAND_

#include "BinaryOp_Command.h"

class Subtract_Command : public BinaryOp_Command
{
    public:
        // Default constructor
        Subtract_Command(void);

        // Destructor
        virtual ~Subtract_Command(void);

        // Evaluate addition operation
        virtual int evaluate(int n1, int n2);

        // Priorty of the operation, (PE)MDEAS
        int priority(void);
};

#endif //!defined _SUBTRACT_COMMAND_
