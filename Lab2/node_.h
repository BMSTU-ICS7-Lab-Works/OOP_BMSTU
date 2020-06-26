#ifndef NODE__H
#define NODE__H

template <typename T>
void Node<T>::set_next(std::shared_ptr<Node<T>> elem)
{
    this->next = elem;
}

template <typename T>
void Node<T>::set_next_null()
{
    this->next = nullptr;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::get_next()
{
    return this->next;
}

#endif // NODE__H
