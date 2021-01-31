#ifndef _EXPR_COMMAND_FACTORY_
#define _EXPR_COMMAND_FACTORY_

#include "Add_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"
#include "Multiply_Command.h"
#include "Number_Command.h"
#include "Subtract_Command.h"

class Expr_Command_Factory
{
    private:
        // These operation should NOT be called in the subclasses
        Expr_Command_Factory(const Expr_Command_Factory &);
        const Expr_Command_Factory & operator = (const Expr_Command_Factory &);

    public:
        // Default constructor
        Expr_Command_Factory(void);

        // Deconstructor
        virtual ~Expr_Command_Factory(void);

        // Commands for each operation type, will return a concrete object
        virtual Add_Command * create_add_command(void) = 0;
        virtual Divide_Command * create_divide_command(void) = 0;
        virtual Modulo_Command * create_modulo_command(void) = 0;
        virtual Multiply_Command * create_multiply_command(void) = 0;
        virtual Number_Command * create_number_command(int number) = 0;
        virtual Subtract_Command * create_subtract_command(void) = 0;
};

#endif //!defined _EXPR_COMMAND_FACTORY_
