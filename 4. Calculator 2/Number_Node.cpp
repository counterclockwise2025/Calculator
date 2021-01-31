#include "Number_Node.h"

Number_Node::Number_Node(int numeric)
    : numeric(numeric)
{
}

Number_Node::~Number_Node(void)
{
}

int Number_Node::evaluate(void) 
{ 
    return this->numeric;
}

void Number_Node::visitor_accept(Visitor& number_node)
{
    number_node.visit(*this);
}

int Number_Node::get_priority(void)
{
    return this->priority;
}
