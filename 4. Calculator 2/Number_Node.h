#ifndef _NUMBER_NODE_
#define _NUMBER_NODE_

#include "Expr_Node.h"

// Forward Declaration
class Visitor;

class Number_Node : public Expr_Node
{
    private:
        int priority = 0;
        int numeric;

    public:
        // Default Constructor
        Number_Node(int numeric);

        // Destructor
        virtual ~Number_Node(void);

        // Evalutor
        virtual int evaluate(void);

        // Visitor acceptence
        virtual void visitor_accept(Visitor& number_visit);

        // Get priority of the number node
        int get_priority(void);
};

#endif //!defined _NUMBER_NODE_
