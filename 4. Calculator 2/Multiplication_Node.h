#ifndef _MULTIPLICATION_NODE_
#define _MULTIPLICATION_NODE_

#include "BinaryExpr_Node.h"

// Forward Declaration
class Visitor;

class Multiplication_Node : public BinaryExpr_Node
{
private:
    int priority = 3;

public:
    // Default constructor
    Multiplication_Node(void);

    // Virtual destructor
    virtual ~Multiplication_Node(void);

    // Take in node objects
    Multiplication_Node(Expr_Node*, Expr_Node*);

    // Accept visitor
    void visitor_accept(Visitor& multiplication_visitor);

    // Get the priorty of the node
    int get_priority(void);
};

#endif //!defined _MULTIPLICATION_NODE_
