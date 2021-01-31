#include "Expr_Tree.h"

Expr_Tree::Expr_Tree(void)
{
}

Expr_Tree::~Expr_Tree(void)
{
}

Expr_Node* Expr_Tree::get_root(void)
{
    return this-> root_;
}

void Expr_Tree::set_root(Expr_Node* root_node)
{
    this->root_ = root_node;
}
