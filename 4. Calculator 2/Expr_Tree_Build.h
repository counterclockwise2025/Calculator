#ifndef _EXPR_TREE_BUILD_
#define _EXPR_TREE_BUILD_

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Expr_Builder.h"
#include "Expr_Tree.h" 
#include "Add_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Multiplication_Node.h"
#include "Number_Node.h"
#include "Subtract_Node.h"

class Expr_Tree_Build : public Expr_Builder
{
    protected:
        Expr_Tree* tree;
        Stack<Expr_Node*> operation_stack;
        Stack<Expr_Node*> lower_operation_stack;
        Queue<Expr_Node*> number_queue;

    public:
        // Default constructor
        Expr_Tree_Build(void);

        // Deconstructor
        ~Expr_Tree_Build(void);

        // Method to place values on to the tree
        bool place_numerics_on_node(Expr_Node* node);

        // Method to retrive the tree
        Expr_Tree* get_tree(void);

        // Build the actual tree
        virtual bool build_tree(Expr_Node* node);
        virtual void place_left(Expr_Node* root_node, Expr_Node* left_node);
        virtual void place_right(Expr_Node* root_node, Expr_Node* right_node);

        // Build each object type node
        virtual void launch_expr(void);
        virtual void build_add_node(void);
        virtual void build_divide_node(void);
        virtual void build_modulus_node(void);
        virtual void build_multiplication_node(void);
        virtual void build_number_node(int numeric);
        virtual void build_subtract_node(void);
};

#endif //!defined _EXPR_TREE_BUILD_
