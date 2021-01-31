#ifndef _BINARYEXPR_NODE_
#define _BINARYEXPR_NODE_

#include "Expr_Node.h"

class BinaryExpr_Node : public Expr_Node
{
    public:
        // Default Constructor
        BinaryExpr_Node(void);

        // Destructor
        virtual ~BinaryExpr_Node(void);
};

#endif //!defined _BINARYEXPR_NODE_
