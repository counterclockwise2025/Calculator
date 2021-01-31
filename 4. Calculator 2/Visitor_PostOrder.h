#ifndef _VISITOR_POSTORDER_
#define _VISITOR_POSTORDER_

#include "Visitor.h"
#include "Stack.h"
#include "Add_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Multiplication_Node.h"
#include "Number_Node.h"
#include "Subtract_Node.h"

class Visitor_PostOrder : public Visitor
{
    private:
        Stack<int> numeric_stack;
        int solution = numeric_stack.top();
        int num1 = 0, num2 = 0;

    public:
        // Default constructor
        Visitor_PostOrder(void);

        // Destructor
        ~Visitor_PostOrder(void);

        // Visit each operator type node
        void visit(Add_Node& add);
        void visit(Divide_Node& divide);
        void visit(Multiplication_Node& multiplication);
        void visit(Modulus_Node& modulus);
        void visit(Number_Node& number);
        void visit(Subtract_Node& subtract);

        // Method for solution
        int answer(void);
};

#endif //!defined _VISITOR_POSTORDER_
