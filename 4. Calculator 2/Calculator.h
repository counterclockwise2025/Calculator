#ifndef _CALCULATOR_
#define _CALCULATOR_

#include <iostream>
#include <sstream>
#include <string>
#include "Expr_Tree_Build.h"
#include "Visitor_PostOrder.h"

class Calculator
{
    private:
        Expr_Tree_Build* builder;
        Visitor_PostOrder* visitor;
        Stack<char> char_stack;
        Stack<char> parenthesis_stack;

    public:

        // Default constructor
        Calculator(void);

        // Destructor 
        ~Calculator(void);

        // Method to take user input and calculate the expression
        int calculate(const std::string& infixed_expr);
};

#endif //!defined _CALCULATOR_
