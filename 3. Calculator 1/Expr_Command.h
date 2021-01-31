#ifndef _EXPR_COMMAND_
#define _EXPR_COMMAND_

#include "Stack.h"      //includes Empty Execption class

//Delcare the excution command class
 class Expr_Command
 {
     public:
        // Execute command
        virtual void execute (Stack<int>& stack) = 0;
 };

 #endif //!defined _EXPR_COMMAND_
