#include "Visitor_PostOrder.h"

Visitor_PostOrder::Visitor_PostOrder(void)
    : numeric_stack(Stack<int>())
    , solution(0)
    , num1(0)
    , num2(0) 
{
}

Visitor_PostOrder::~Visitor_PostOrder(void)
{
}

void Visitor_PostOrder::visit(Add_Node& add)
{
    // Obtain the contained data within the respective nodes
    add.get_left()->visitor_accept(*this);
    add.get_right()->visitor_accept(*this);
    
    // Pop the values off the stack to be evaluated
    num2 = numeric_stack.top();
    numeric_stack.pop();
    num1 = numeric_stack.top();
    numeric_stack.pop();

    // Complete the operation and store the result
    solution = num1 + num2;

    // Push result back on to stack
    numeric_stack.push(solution);
}

void Visitor_PostOrder::visit(Divide_Node& divide)
{
    // Obtain the contained data within the respective nodes
    divide.get_left()->visitor_accept(*this);
    divide.get_right()->visitor_accept(*this);

    // Pop the values off the stack to be evaluated
    num2 = numeric_stack.top();
    numeric_stack.pop();
    num1 = numeric_stack.top();
    numeric_stack.pop();

    // Complete the operation and store the result
    solution = num1/num2;

    // Push result back on to stack
    numeric_stack.push(solution);
}

void Visitor_PostOrder::visit(Modulus_Node& modulus)
{
    // Obtain the contained data within the respective nodes
    modulus.get_left()->visitor_accept(*this);
    modulus.get_right()->visitor_accept(*this);

    // Pop the values off the stack to be evaluated
    num2 = numeric_stack.top();
    numeric_stack.pop();
    num1 = numeric_stack.top();
    numeric_stack.pop();

    // Complete the operation and store the result
    solution = num1 % num2;

    // Push result back on to stack
    numeric_stack.push(solution);
}

void Visitor_PostOrder::visit(Multiplication_Node& multiply)
{
    // Obtain the contained data within the respective nodes
    multiply.get_left()->visitor_accept(*this);
    multiply.get_right()->visitor_accept(*this);

    // Pop the values off the stack to be evaluated
    num2 = numeric_stack.top();
    numeric_stack.pop();
    num1 = numeric_stack.top();
    numeric_stack.pop();

    // Complete the operation and store the result
    solution = num1 * num2;

    // Push result back on to stack
    numeric_stack.push(solution);
}

void Visitor_PostOrder::visit(Number_Node& number)
{
    numeric_stack.push(number.evaluate());
}

void Visitor_PostOrder::visit(Subtract_Node& subtract)
{
    // Obtain the contained data within the respective nodes
    subtract.get_left()->visitor_accept(*this);
    subtract.get_right()->visitor_accept(*this);

    // Pop the values off the stack to be evaluated
    num2 = numeric_stack.top();
    numeric_stack.pop();
    num1 = numeric_stack.top();
    numeric_stack.pop();

    // Complete the operation and store the result
    solution = num1 - num2;

    // Push result back on to stack
    numeric_stack.push(solution);
}

int Visitor_PostOrder::answer(void)
{
    return solution;
}
