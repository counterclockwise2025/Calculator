#include "Calculator.h"

int main()
{
    std::cout << "Expression Tree Evaluator " << std::endl;

    std::string user_input = "";
    bool keep_going = true;

    while (keep_going)
    {
        Calculator calculator = Calculator();
        std::cin.clear();
        std::cout << "Please enter an expression: " << std::endl;
        std::getline(std::cin, user_input);

        if (user_input == "QUIT")
        {
            keep_going = false;
            std::cout << "Exiting Program..." << std::endl;
        }

        else
        {
            int answer = calculator.calculate(user_input);
            std::cout << answer << std::endl;
            keep_going = true;
        }
    }
    return 0;
}

// COMMENT Your current design is using the builder pattern, but not fully
// using it and going against its intent. The client should not be aware
// of how anything is handled related to the construction of the complex
// object. In your code below, the client is aware of how to handle parenthesis.
// This logic should be embedded in the concrete builder. The client should not
// contain any logic related to the "construction" of the complex object.

// RESPONSE I went ahead and moved the method into the Calculator class which handles the expression
// given by the user so that way the client does not know how to calculate the expression but rather, 
// it uses a calculator to solve the expression.
