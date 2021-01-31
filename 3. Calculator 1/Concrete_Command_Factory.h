#ifndef _CONCRETE_COMMAND_FACTORY_
#define _CONCRETE_COMMAND_FACTORY_

#include "Expr_Command_Factory.h"

class Concrete_Command_Factory : public Expr_Command_Factory
{
    public:
        // Default constructor
        Concrete_Command_Factory(void);

        // Deconstructor
        virtual ~Concrete_Command_Factory(void);

        // Commands for each operation type, will return a concrete object
        virtual Add_Command *create_add_command(void);
        virtual Divide_Command *create_divide_command(void);
        virtual Modulo_Command *create_modulo_command(void);
        virtual Multiply_Command *create_multiply_command(void);
        virtual Number_Command *create_number_command(int number);
        virtual Subtract_Command *create_subtract_command(void);
};

#endif //!defined 
