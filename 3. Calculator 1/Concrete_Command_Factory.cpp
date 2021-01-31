#include "Concrete_Command_Factory.h"

// Construct the process
Concrete_Command_Factory::Concrete_Command_Factory(void)
{
}

Concrete_Command_Factory::~Concrete_Command_Factory(void)
{
}

Add_Command * Concrete_Command_Factory::create_add_command()
{
    return new Add_Command();
}

Divide_Command * Concrete_Command_Factory::create_divide_command()
{
    return new Divide_Command();
}

Modulo_Command * Concrete_Command_Factory::create_modulo_command()
{
    return new Modulo_Command();
}

Multiply_Command * Concrete_Command_Factory::create_multiply_command()
{
    return new Multiply_Command();
}

Number_Command * Concrete_Command_Factory::create_number_command(int number)
{
    return new Number_Command(number);
}

Subtract_Command * Concrete_Command_Factory::create_subtract_command()
{
    return new Subtract_Command();
}
