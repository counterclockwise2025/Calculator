#ifndef _ADD_COMMAND_
#define _ADD_COMMAND_

#include "BinaryOp_Command.h"

class Add_Command : public BinaryOp_Command
{
    public:
        // Default constructor
        Add_Command (void);

        // Destructor
        virtual ~Add_Command (void);

        // Evaluate addition operation
        virtual int evaluate (int n1, int n2);

        // Priorty of the operation, (PE)MDEAS
        int priority(void);
};

#endif //!defined _ADD_COMMAND_
