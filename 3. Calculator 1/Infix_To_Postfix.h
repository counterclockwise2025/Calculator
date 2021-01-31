#ifndef _INFIX_TO_POSTFIX_
#define _INFIX_TO_POSTFIX_

#include <iostream>
#include <sstream>
#include <string>
#include "Expr_Command.h"
#include "Concrete_Command_Factory.h"
#include "Expr_Command_Iterator.h"

class Infix_To_Postfix
{ 
    public:
        // Default Constructor
        Infix_To_Postfix(void);

        // Destructor
        ~Infix_To_Postfix(void);
        
        // Making a tempoary function to get this to work
        int precendence(char user_string);
        
        // Check if the value is a number
        bool is_Number(int input);

        // Infix to Postfix conversion
        std::string in_to_post_conversion(std::string infix);

        // Read the user input and parse
        Array<Expr_Command*> calculator_parser(std::string postfix);

        // Evaluate postfix form
        int postfix_evaluation(Array<Expr_Command *> postfix_format);
};

#endif //!defined _INFIX_TO_POSTFIX_
