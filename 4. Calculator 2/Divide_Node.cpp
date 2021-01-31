#include "Divide_Node.h"

Divide_Node::Divide_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Divide_Node::~Divide_Node(void)
{
}

Divide_Node::Divide_Node(Expr_Node* num1, Expr_Node* num2)
{
    this->left_ = num1;
    this->right_ = num2;
}

void Divide_Node::visitor_accept(Visitor& divide_visit)
{
    divide_visit.visit(*this);
}

int Divide_Node::get_priority(void)
{
    return this->priority;
}
