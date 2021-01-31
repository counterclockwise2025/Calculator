#include "Number_Command.h"

Number_Command::Number_Command(void)
{
}

Number_Command::~Number_Command(void)
{
}

// Call constructor
Number_Command::Number_Command(int number)
    : stack_num(number)
{
}

// Execute the evaluation on the stack
void Number_Command::execute(Stack<int> & stack)
{
    stack.push(evaluate(stack_num));
}

// Evaluate the number
int Number_Command::evaluate(int number)
{
    return number;
}
