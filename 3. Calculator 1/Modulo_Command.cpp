#include "Modulo_Command.h"

Modulo_Command::Modulo_Command(void)
{
}

Modulo_Command::~Modulo_Command(void)
{
}

int Modulo_Command::evaluate(int n1, int n2)
{
    return n1%n2;
}

int Modulo_Command::priority(void)
{
    return 1;
}
