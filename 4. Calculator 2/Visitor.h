#ifndef _VISITOR_
#define _VISITOR_

class Add_Node;
class Divide_Node;
class Modulus_Node;
class Multiplication_Node;
class Number_Node;
class Subtract_Node;

class Visitor
{
    // Interface for the visitor
    public: 
        virtual void visit(Add_Node& add) = 0;
        virtual void visit(Divide_Node& divide) = 0;
        virtual void visit(Modulus_Node& modulus) = 0;
        virtual void visit(Multiplication_Node& multiply) = 0;
        virtual void visit(Number_Node& numeric) = 0;
        virtual void visit(Subtract_Node& subtract) = 0;
};

#endif //!defined _VISITOR_
