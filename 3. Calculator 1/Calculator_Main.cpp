#include "Infix_To_Postfix.h"

int main()
{
    std::cout << "Postfix Expression Evaluator " << std::endl;

    std::string user_input = "";
    bool keep_going = true;

    Infix_To_Postfix InF = Infix_To_Postfix();

    while (keep_going)
    {
        std::cin.clear();
        std::cout << "Please enter your math problem: " << std::endl;
        std::getline(std::cin, user_input);

        if (user_input == "QUIT")
        {
            keep_going = false;
            std::cout << "Exiting Program..." << std::endl;
        }

        else
        {
            std::string postfix_converted = InF.in_to_post_conversion(user_input);
            Array<Expr_Command*> array_of_command_expr = InF.calculator_parser(postfix_converted);
            int users_solution = InF.postfix_evaluation(array_of_command_expr);
            std::cout << users_solution << std::endl;

            keep_going = true;
        }
    }
    return 0;
}