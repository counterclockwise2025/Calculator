#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Multiplication_Node::~Multiplication_Node(void)
{
}

Multiplication_Node::Multiplication_Node(Expr_Node* num1, Expr_Node* num2)
{
    this->left_ = num1;
    this->right_ = num2;
}

void Multiplication_Node::visitor_accept(Visitor& multiplication_visit)
{
    multiplication_visit.visit(*this);
}

int Multiplication_Node::get_priority(void)
{
    return this->priority;
}
