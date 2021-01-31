#include "Expr_Node.h"

Expr_Node::Expr_Node(void)
{
}

Expr_Node::Expr_Node(int num)
{
}

Expr_Node::~Expr_Node(void)
{
    delete left_;
    delete right_;
}

Expr_Node::Expr_Node(Expr_Node* left_node, Expr_Node* right_node)
{
    this->left_ = left_node;
    this->right_ = right_node;
}

Expr_Node* Expr_Node::get_left(void)
{
    return this->left_;
}

Expr_Node* Expr_Node::get_right(void)
{
    return this->right_;
}

void Expr_Node::set_left(Expr_Node* left_node)
{
    this->left_ = left_node;
}

void Expr_Node::set_right(Expr_Node* right_node)
{
    this->right_ = right_node;
}
