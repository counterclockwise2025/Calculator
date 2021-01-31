#ifndef _EXPR_BUILDER_
#define _EXPR_BUILDER_

class Expr_Builder
{
    /**
     * Interface methods to build each node type.
    */
    public:
        virtual void launch_expr() = 0;
        virtual void build_add_node(void) = 0;
        virtual void build_divide_node(void) = 0;
        virtual void build_modulus_node(void) = 0;
        virtual void build_multiplication_node(void) = 0;
        virtual void build_number_node(int numeric) = 0;
        virtual void build_subtract_node(void) = 0;
};

#endif //!defined _EXPR_BUILDER_
