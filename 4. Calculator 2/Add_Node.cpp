#include "Add_Node.h"

Add_Node::Add_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Add_Node::~Add_Node(void)
{
}

Add_Node::Add_Node(Expr_Node* num1, Expr_Node* num2)
{
    this->left_ = num1;
    this->right_ = num2;
}

void Add_Node::visitor_accept(Visitor& add_visit)
{
    add_visit.visit(*this);
}

int Add_Node::get_priority(void)
{
    return this->priority;
}
