#include "Subtract_Node.h"

Subtract_Node::Subtract_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Subtract_Node::~Subtract_Node(void)
{
}

Subtract_Node::Subtract_Node(Expr_Node* num1, Expr_Node* num2)
{
    this->left_ = num1;
    this->right_ = num2;
}

void Subtract_Node::visitor_accept(Visitor& subtract_visit)
{
    subtract_visit.visit(*this);
}

int Subtract_Node::get_priority(void)
{
    return this->priority;
}
