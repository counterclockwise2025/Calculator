#include "Infix_To_Postfix.h"

Infix_To_Postfix::Infix_To_Postfix(void)
{
}

Infix_To_Postfix::~Infix_To_Postfix(void)
{
}

// Defining precendence function to make this work since my objects are not
int Infix_To_Postfix::precendence(char user_string)
{
    if (user_string == '*' || user_string == '/')
        return 2;
    else if (user_string == '+' || user_string == '-' || user_string == '%')
        return 1;
    else
        return -1;
}

// Check if the string input is a numeric
bool Infix_To_Postfix::is_Number(int input)
{
    bool result = false;
        if (isdigit(input))
        {
            result = true;
        }

        else
        {
            result = false;
        }
        
    return result;
}

// Infix to postfix conversion
std::string Infix_To_Postfix::in_to_post_conversion(std::string infix)
{
    std::istringstream input(infix); 
    Stack<char> parentheses = Stack<char>();
    std::string postfix_form;
    std::string user_token;

    for (int i = 0; i < infix.length(); i++)
    {
        input >> user_token;
        // If the operator scanned is changed to integer then add
        // output string
        if (is_Number(std::stoi(user_token)))
        {
            postfix_form += user_token[i];
        }

        // If scanned character is '(' then push to
        // parentheses stack.
        else if (user_token[i] == '(')
        {
            parentheses.push(user_token[i]);
        }

        // If scanned character is a ')' pop and add to string
        // till the '(' is encountered.
        else if (user_token[i] == ')')
        {
            while (parentheses.top() != '(')
            {
                char char_from_string = parentheses.top(); 
                parentheses.pop();
                postfix_form += char_from_string;
            }
            
            if(parentheses.top() == '(')
            {
                char char_from_string = parentheses.top();
                parentheses.pop();
            }
        }

        // Checking for scanned operator
        else
        {
            while (!parentheses.is_empty() && precendence(user_token[i]) <= precendence(parentheses.top()))
            {
                char operator_from_string = parentheses.top();
                parentheses.pop();
                postfix_form += operator_from_string;
            }
        }
    }

    // Pop remaining elements from the stack
    while (parentheses.top() != '(' && parentheses.size() != 0)
    {
        char remaining_elements = parentheses.top();
        parentheses.pop();
        postfix_form += remaining_elements;
    }
    
    return postfix_form;
} // end conversion method

// Parse that will take the postfix formated string.
// Convert the string characters to objects using the factory.
// Returns a array of expression commands object.
Array<Expr_Command*> Infix_To_Postfix::calculator_parser(std::string postfix)
{
    int postfix_arr_pointer = 0;
    std::string user_token;
    std::istringstream input(postfix);
    Stack<char> parentheses_stack = Stack<char>(); // Make a seprate stack for paratheses to be placed on.
    Stack<Expr_Command*> stack_expr = Stack<Expr_Command*>();
    Expr_Command* command = 0; // Declared but not instantiated object
    Concrete_Command_Factory expr_factory;
    Array<Expr_Command *> postfix_expr = Array<Expr_Command *>(postfix.length()); // Add the factory commands here

    bool numeric = false;

        int index = 0;
        while (!input.eof())
        {
            // Set the input into the users token
            input >> user_token;

            if(user_token == ")")
            {
                while(parentheses_stack.top() != '(' && parentheses_stack.size() != 0)
                {
                    postfix_expr.set(postfix_arr_pointer, stack_expr.top());
                    parentheses_stack.pop();
                    stack_expr.pop(); 
                    postfix_arr_pointer++;
                }
                
                if(parentheses_stack.top() == '(')
                {
                    parentheses_stack.pop();
                }
            }

            else if (user_token == "(")
            {
                parentheses_stack.push('(');
            }

            // Parsing through the string and serach for operators
            else if(user_token == "+")
            {
                command = expr_factory.create_add_command();
            }

            else if(user_token == "/")
            {
                command = expr_factory.create_divide_command();
            }

            else if(user_token == "%")
            {
                command = expr_factory.create_modulo_command();
            }
            
            else if(user_token == "*")
            {
                command = expr_factory.create_multiply_command();
            }
            
            else if(user_token == "-")
            {
                command = expr_factory.create_subtract_command();
            }

            else
            {
                command = expr_factory.create_number_command(std::stoi(user_token));
                numeric = true;
            }

            postfix_expr.set(index, command);
            index++;
        }

    return postfix_expr;
} // end parser method

// Function to evaluate the expression. Loops through the iteration and moves the pointer. Execute each operation.
// Once stack is reduce and == 1 then the solution is found.
int Infix_To_Postfix::postfix_evaluation(Array<Expr_Command *> postfix_format)
{
    int solution = 0;
    int iterator = 0;
    Stack<int> stack;

    for (int i = 0; i < postfix_format.size(); i++)
    {
        postfix_format[i]->execute(stack);
    }

    if (stack.size() == 1)
    {
        solution = stack.top();
    }

    else
    {
        throw Empty_Exception("operation invalid");
    }

    return solution;
} //end evaluation method
