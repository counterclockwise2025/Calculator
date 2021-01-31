#include "Divide_Command.h"

Divide_Command::Divide_Command(void)
{
}

Divide_Command::~Divide_Command(void)
{
}

int Divide_Command::evaluate (int n1, int n2)
{
    if(n2 == 0)
    {
        throw Empty_Exception("Cannot divide by 0");
    }

    return n1/n2;
}

int Divide_Command::priority(void)
{
    return 1;
}
