#ifndef _EXPR_NODE_
#define _EXPR_NODE_

#include "Visitor.h"

class Expr_Node
{
    protected:
        Expr_Node* left_ = nullptr;
        Expr_Node* right_ = nullptr;

    public:
        // Default constructor
        Expr_Node(void);

        // Expression node for integer
        Expr_Node(int num);

        // Taking in experssion node objects
        Expr_Node(Expr_Node*, Expr_Node*);

        // Destructor
        virtual ~Expr_Node(void);

        // Get left node
        virtual Expr_Node* get_left(void);

        // Get right node
        virtual Expr_Node* get_right(void);

        // Set the left node value
        virtual void set_left(Expr_Node*);

        // Set the right node value
        virtual void set_right(Expr_Node*);

        // Allow visitor access
        virtual void visitor_accept(Visitor& visitor) = 0;

        // Get priority
        virtual int get_priority(void) = 0;
};

#endif //!defined _EXPR_NODE_
