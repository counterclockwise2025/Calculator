#include "Expr_Tree_Build.h"

Expr_Tree_Build::Expr_Tree_Build(void)
    : tree(new Expr_Tree())
    , operation_stack(Stack<Expr_Node*>())
    , lower_operation_stack(Stack<Expr_Node*>())
    , number_queue(Queue<Expr_Node*>())
{
}

Expr_Tree_Build::~Expr_Tree_Build(void)
{
    delete tree;
}

bool Expr_Tree_Build::place_numerics_on_node(Expr_Node* root)
{
    // If queue of numbers is not empty then check
    if (!number_queue.is_empty())
    {
        // Check left and right right of root to see if their child nodes contain any value 
        if (root->get_left() == nullptr && root->get_right() == nullptr)
        {
            // If the child nodes do not contain anything then take the values off the queue and set each one respecitivly 
            root->set_left(number_queue.dequeue());
            root->set_right(number_queue.dequeue());
        }

        // If the left node child contains no value and the right node has a value
        else if (root->get_left() == nullptr && root->get_right() != nullptr)
        {   
            // Then set left node to a value of the queue
            root->set_left(number_queue.dequeue());

            // If the right node priority of the object is not 0 then set it to a value 
            if (root->get_right()->get_priority() != 0)
            {
                place_numerics_on_node(root->get_right());
            }
        }
        
        // If left child has a value and the right child doesn't have a value
        else if (root->get_left() != nullptr && root->get_right() == nullptr)
        {
            // Set the right child to the value of the dequeued Expr_Node.
            root->set_right(number_queue.dequeue());
        }

        // If the left and right child nodes of the root contain an object
        else if (root->get_left() != nullptr && root->get_right() != nullptr)
        {
            // Then place a number on the left child node
            place_numerics_on_node(root->get_left());

            // If the right side priority is not 0 then set it to a value
            if (root->get_right()->get_priority() != 0)
            {
                place_numerics_on_node(root->get_right());
            }
        }

        // If the right object node contains a priority not equal to 0
        else if (root->get_right()->get_priority() != 0)
        {
            // Place a number on the right object node
            place_numerics_on_node(root->get_right());
        }
    }

    // Number queue is empty then return true
    else
    {
        return true;
    }
}

Expr_Tree* Expr_Tree_Build::get_tree(void)
{
    return tree;
}

bool Expr_Tree_Build::build_tree(Expr_Node* node)
{
    // temporary stack
    Stack<Expr_Node*> temp_stack;

    // Made this statement into a boolean variable b/c it was too long.
    bool stack_not_empty_and_priority_less_than_one = !operation_stack.is_empty() && 1 < operation_stack.top()->get_priority();

    // if stack of operations is not empty and 
    if (stack_not_empty_and_priority_less_than_one)
    {
        // While operator stack does not have priority that has the same value as the lower operation stack
        while (stack_not_empty_and_priority_less_than_one)
        {
            // Then push the top of the operation stack to the tempoary stack until that matches the lower operation stack
            temp_stack.push(operation_stack.top());
            operation_stack.pop();

            // Check if both operation stacks are empty
            if (lower_operation_stack.is_empty() && operation_stack.is_empty())
            {
                // then if the root points to an empty object
                if (tree->get_root() == nullptr)
                {
                    // If so then set the value of it to the what is on the tempoary stack and pop
                    tree->set_root(temp_stack.top());
                    temp_stack.pop();
                }
                // If not then set the value of the node to whatever is on top of the tempoary stack and pop
                else
                {
                    node = temp_stack.top();
                    temp_stack.pop();
                }
            }
            // If the stacks are not empty
            else
            {
                // If operation stack is empty and the tempoary stack is not
                if (operation_stack.is_empty() && !temp_stack.is_empty())
                {
                    // Then get the root and check if the node object is empty
                    if (tree->get_root() == nullptr)
                    {
                        // set the root value to the top of the tempoary stack value
                        tree->set_root(temp_stack.top());
                        temp_stack.pop();

                        // if low operation stakc is not empty then pop
                        if (!lower_operation_stack.is_empty())
                        {
                            lower_operation_stack.pop();
                        }
                    }
                }
                
                // If both stacks (opeartion and lower) have the same value
                else
                {
                    // Set the value of the root to whatever is on the operation stack and pop both stacks
                    if (tree->get_root() == nullptr)
                    {
                        tree->set_root(operation_stack.top());
                        operation_stack.pop();
                        if (!lower_operation_stack.is_empty())
                        {
                            lower_operation_stack.pop();
                        }
                    }

                    // If the node is pointing to nothing then set the the node value to whatever is on top of the operation stack and pop
                    else if (node == nullptr)
                    {
                        node = operation_stack.top();
                        operation_stack.pop();
                        if (!lower_operation_stack.is_empty())
                        {
                            lower_operation_stack.pop();
                        }
                    }

                    // If the condtions above are not caught then just do the same thing again 
                    else
                    {
                        node = operation_stack.top();
                        operation_stack.pop();
                        if (!lower_operation_stack.is_empty())
                        {
                            lower_operation_stack.pop();
                        }
                    }
                }
            }

            // While the tempoary stack is not empty
            while (!temp_stack.is_empty())
            {
                // If the root has something and the object node is nothing
                if (tree->get_root() != nullptr && node == nullptr)
                {
                    // Set the root to the right side and set it towards the right and place the value of tempoary stack to the right
                    place_right(tree->get_root(), temp_stack.top());
                    temp_stack.pop();
                }
                else
                {
                    place_right(node, temp_stack.top());
                    temp_stack.pop();
                }
            }

            // If the node has a value 
            if (node != nullptr)
            {
                // Start the tree to the left
                place_left(tree->get_root(), node);
            }

            // If the operation stack is empty
            if (!operation_stack.is_empty())
            {
                // Then use recursion to keep the stack moving
                build_tree(tree->get_root()->get_left());
            }

            else
            {
                return true;
            }
        }
    }

    // Everything else on the lower operation stack
    else
    {
        // If the root has nothing
        if (tree->get_root() == nullptr)
        {
            // Set whatever is left on operation stack to it and pop
            tree->set_root(operation_stack.top());
            operation_stack.pop();
        }

        // If the root has something
        else
        {
            // Then tell the node to take the value of the operation stack and pop
            node = operation_stack.top();
            operation_stack.pop();

            // If the operation stack is not empty 
            if (!operation_stack.is_empty())
            {
                // Start building the tree using recursion 
                build_tree(tree->get_root()->get_left());
            }
            
            else
            {
                return true;
            }
        }
    }
}

void Expr_Tree_Build::place_left(Expr_Node* root_node, Expr_Node* left_node)
{
    if (root_node->get_left() == nullptr)
    {
        root_node->set_left(left_node);
    }
    else
    {
        place_left(root_node->get_left(), left_node);
    }
}

void Expr_Tree_Build::place_right(Expr_Node* root_node, Expr_Node* right_node)
{
    if (root_node->get_right() == nullptr)
    {
        root_node->set_right(right_node);
    }
    else
    {
        place_right(root_node->get_right(), right_node);
    }
}

void Expr_Tree_Build::launch_expr(void)
{
    this->tree = new Expr_Tree();
}

void Expr_Tree_Build::build_add_node(void)
{
    Expr_Node* add = new Add_Node();
    operation_stack.push(add);
    lower_operation_stack.push(add);
}

void Expr_Tree_Build::build_divide_node(void)
{
    Expr_Node* divide = new Divide_Node();
    operation_stack.push(divide);
}

void Expr_Tree_Build::build_modulus_node(void)
{
    Expr_Node* modulus = new Modulus_Node();
    operation_stack.push(modulus);
}

void Expr_Tree_Build::build_multiplication_node(void)
{
    Expr_Node* multiply = new Multiplication_Node();
    operation_stack.push(multiply);
}

void Expr_Tree_Build::build_number_node(int numeric)
{
    Expr_Node* number = new Number_Node(numeric);
    number_queue.enqueue(number);
}

void Expr_Tree_Build::build_subtract_node(void)
{
    Expr_Node* subtract = new Subtract_Node();
    lower_operation_stack.push(subtract);
    operation_stack.push(subtract);
}
