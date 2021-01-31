#ifndef _SUBTRACT_NODE_
#define _SUBTRACT_NODE_

#include "BinaryExpr_Node.h"

// Forward Declaration
class Visitor;

class Subtract_Node : public BinaryExpr_Node
{
    private:
        int priority = 1;

    public:
        // Default constructor
        Subtract_Node(void);

        // Deconstrcutor
        virtual ~Subtract_Node(void);

        // Take in node objects
        Subtract_Node(Expr_Node*, Expr_Node*);

        // Visitor acceptence
        virtual void visitor_accept(Visitor& subtract_visit);

        // Get the priority of the subtract node
        int get_priority(void);
};

#endif //!defined _SUBTRACT_NODE_
