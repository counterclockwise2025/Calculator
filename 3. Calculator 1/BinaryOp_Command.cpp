#include "BinaryOp_Command.h"
#include "Empty_Exception.h"

BinaryOp_Command::BinaryOp_Command(void)
{
}

BinaryOp_Command::~BinaryOp_Command(void)
{
}

void BinaryOp_Command::execute(Stack<int> & stack)
{
    int stack_n1, stack_n2;

    try
    {
        // Pop first value on the top of the stack
        stack_n1 = stack.top();
        stack.pop();

        // Pop second value at the top of the stack
        stack_n2 = stack.top();
        stack.pop();

        // Evaluate the values and then push back result to the stack
        stack.push(evaluate(stack_n1, stack_n2));
    }

    catch(Empty_Exception)
    {
        throw Empty_Exception("This operation cannot be completed");
    }
}
