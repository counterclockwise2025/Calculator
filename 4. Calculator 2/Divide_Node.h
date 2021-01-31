#ifndef _DIVIDE_NODE_
#define _DIVIDE_NODE_

#include "BinaryExpr_Node.h"

// Forward Declaration
class Visitor;

class Divide_Node : public BinaryExpr_Node
{
    private:
        int priority = 3;

    public:
        // Default Constructor
        Divide_Node(void);

        // Virtual destructor
        virtual ~Divide_Node(void);

        // Take in node objects
        Divide_Node(Expr_Node*, Expr_Node*);

        // Accept visitor
        void visitor_accept(Visitor& divide_node_visitor);

        // Get the priorty of the node
        int get_priority(void);
};

#endif //!defined _DIVIDE_NODE_
