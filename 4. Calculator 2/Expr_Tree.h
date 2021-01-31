#ifndef _EXPR_TREE_
#define _EXPR_TREE_

#include "Expr_Node.h"

// Forward Declaration
class Expr_Node;

class Expr_Tree
{
    private:
        Expr_Node* root_ = nullptr;

    public:
        // Default constructor
        Expr_Tree(void);

        // Destructor
        ~Expr_Tree(void);

        // Get the root of the tree
        Expr_Node* get_root(void);

        // Set the root node value
        void set_root(Expr_Node*);
};

#endif //!defined _EXPR_TREE_
