#include "Add_Command.h"

Add_Command::Add_Command(void)
{
}

Add_Command::~Add_Command(void)
{
}

int Add_Command::evaluate (int n1, int n2)
{
    return n1 + n2;
}

int Add_Command::priority(void)
{
    return 2;
}
