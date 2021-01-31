template <typename T>
Expr_Command_Iterator<T>::Expr_Command_Iterator(Array<T>& e, int postfix_position)
    : expr_array(e)
    , current_position(0)
    , max_size_(postfix_position)
{
}

template <typename T>
void Expr_Command_Iterator<T>::advance(void)
{
    this->current_postion++;
}

template <typename T>
bool Expr_Command_Iterator<T>::is_done(void)
{
    return this->current_position == this->expr_array.max_size_;
}

template <typename T>
T Expr_Command_Iterator<T>::operator * (void)
{
    return this->expr_array.data_[this->current_position];
}

template <typename T>
T * Expr_Command_Iterator<T>::operator -> (void)
{
    return &this->expr_array.data_[this->current_position];
}
