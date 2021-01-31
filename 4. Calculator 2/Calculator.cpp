#include "Calculator.h"

Calculator::Calculator(void)
    : builder(new Expr_Tree_Build())
    , visitor(new Visitor_PostOrder())
    , char_stack(Stack<char>())
    , parenthesis_stack(Stack<char>())
{
}

Calculator::~Calculator(void)
{
    delete builder;
    delete visitor;
}

int Calculator::calculate(const std::string& infixed_expr)
{
    // Building the tree
    std::istringstream input(infixed_expr);

    std::string user_token;

    // The builder
    Expr_Tree_Build* builder = new Expr_Tree_Build();
    builder->launch_expr();

    // The Visitor
    Visitor_PostOrder* visitor = new Visitor_PostOrder();

    Stack<char> char_stack = Stack<char>();
    Stack<char> parentheses_stack = Stack<char>();

    int number = 0;
    // Input is not finished
    while (!input.eof())
    {
        int position = 0;
        input >> user_token;

        // If parentheses stack is not empty then create each type of object using the operator encountered
        if (parentheses_stack.is_empty())
        {
            if (user_token == "+")
            {
                builder->build_add_node();
                position++;
            }
            else if (user_token == "/")
            {
                builder->build_divide_node();
                position++;
            }
            else if (user_token == "%")
            {
                builder->build_modulus_node();
                position++;
            }
            else if (user_token == "*")
            {
                builder->build_multiplication_node();
                position++;
            }
            else if (user_token == "-")
            {
                builder->build_subtract_node();
                position++;
            }
            else if (user_token == "(")
            {
                parentheses_stack.push('(');
                position++;
            }
            else
            {
                number = std::stoi(user_token);
                builder->build_number_node(number);
                position++;
            }
        }
        else
        {
            // If an open "(" is encounted then then check if string stack is empty and push to parentheses stack
            if (user_token == "(")
            {
                if (char_stack.is_empty())
                {
                    parentheses_stack.push('(');
                }

                // If the string stack is not empty then create each type of object using the operator encountered
                else
                {
                    while (!char_stack.is_empty())
                    {
                        if (char_stack.top() == '+')
                        {
                            builder->build_add_node();
                            position++;
                        }
                        else if (char_stack.top() == '/')
                        {
                            builder->build_divide_node();
                            position++;
                        }
                        else if (char_stack.top() == '%')
                        {
                            builder->build_modulus_node();
                            position++;
                        }
                        else if (char_stack.top() == '*')
                        {
                            builder->build_multiplication_node();
                            position++;
                        }
                        else if (char_stack.top() == '-')
                        {
                            builder->build_subtract_node();
                            position++;
                        }
                        char_stack.pop();
                    }
                    parentheses_stack.push('(');
                }
            }

            // If an open ")" is encounted then then pop parentheses stack
            else if (user_token == ")")
            {
                parentheses_stack.pop();

                // If the parentheses stack is empty then create each type of object using the operator encountered
                if (parentheses_stack.is_empty())
                {
                    while (!char_stack.is_empty())
                    {
                        if (char_stack.top() == '+')
                        {
                            builder->build_add_node();
                            position++;
                        }
                        else if (char_stack.top() == '/')
                        {
                            builder->build_divide_node();
                            position++;
                        }
                        else if (char_stack.top() == '%')
                        {
                            builder->build_modulus_node();
                            position++;
                        }
                        else if (char_stack.top() == '*')
                        {
                            builder->build_multiplication_node();
                            position++;
                        }
                        else if (char_stack.top() == '-')
                        {
                            builder->build_subtract_node();
                            position++;
                        }
                        char_stack.pop();
                    }
                }
            }

            // If the token matches a specific character then push the token to the string stack
            else if (user_token == "*" || user_token == "/" || user_token == "%" || user_token == "+" || user_token == "-")
            {
                char_stack.push(user_token.at(position));
                position++;
            }

            // Create a number using the string input and tell that to create the numeric object type
            else
            {
                number = std::stoi(user_token);
                builder->build_number_node(number);
                position++;
            }
        } 
    } // end while

    // evaluating expression using the visitor
    builder->get_tree()->get_root()->visitor_accept(*visitor);
    
    // returning answer
    int results = visitor->answer();
    return results;
}