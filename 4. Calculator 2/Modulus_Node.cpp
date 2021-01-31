#include "Modulus_Node.h"

Modulus_Node::Modulus_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Modulus_Node::~Modulus_Node(void)
{
}

Modulus_Node::Modulus_Node(Expr_Node* num1, Expr_Node* num2)
{
    this->left_ = num1;
    this->right_ = num2;
}

void Modulus_Node::visitor_accept(Visitor& modulus_visit)
{
    modulus_visit.visit(*this);
}

int Modulus_Node::get_priority(void)
{
    return this->priority;
}
