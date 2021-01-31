#ifndef _MODULUS_NODE_
#define _MODULUS_NODE_

#include "BinaryExpr_Node.h"

// Forward Declaration
class Visitor;

class Modulus_Node : public BinaryExpr_Node
{
    private:
        int priority = 3;

    public:
        // Default constructor
        Modulus_Node(void);

        // Virtual destructor
        virtual ~Modulus_Node(void);

        // Take in node objectsn
        Modulus_Node(Expr_Node*, Expr_Node*);

        // Accept visitor
        void visitor_accept(Visitor& modulus_Node_visitor);

        // Get the priorty of the node
        int get_priority(void);
};

#endif //!defined _MODULUS_NODE_
