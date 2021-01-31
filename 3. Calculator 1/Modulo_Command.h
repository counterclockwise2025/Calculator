#ifndef _MODULO_COMMAND_
#define _MODULO_COMMAND_

#include "BinaryOp_Command.h"

class Modulo_Command : public BinaryOp_Command
{
    public:
        // Default constructor
        Modulo_Command(void);

        // Destructor
        virtual ~Modulo_Command(void);

        // Evaluate addition operation
        virtual int evaluate(int n1, int n2);

        // Priorty of the operation, (PE)MDEAS
        int priority(void);
};

#endif //!defined _MODULO_COMMAND_
