#ifndef _ADD_NODE_
#define _ADD_NODE_

#include "BinaryExpr_Node.h"

// Forward Declaration
class Visitor;

class Add_Node : public BinaryExpr_Node
{
    private:
        int priority = 1;

    public:
        // Default constructor
        Add_Node(void);

        // Virtual destructor
        virtual ~Add_Node(void);

        // Take in node objects
        Add_Node(Expr_Node*, Expr_Node*);

        // Accept visitor
        void visitor_accept(Visitor& add_node_visitor);

        // Get the priorty of the node
        int get_priority(void);
};

#endif //!defined _ADD_NODE_
