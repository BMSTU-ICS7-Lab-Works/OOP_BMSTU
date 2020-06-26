#ifndef LIST__H
#define LIST__H

//#include "list.hpp"
#include <stdlib.h>
#include <ctime>
#include "cstddef"
#include "node.hpp"
#include <initializer_list>
#include <iostream>
#include "m_exception.hpp"

template<typename T>

List<T>::List()
{
    head = NULL;
}

template<typename T>
List<T>::List(const List<T> &lst)
{
    copy(lst);
}

template<typename T>
List<T> &List<T>::operator= (List const &lst)
{
    clear();
    copy(lst);
    return *this;
}

template<typename T>
List<T>::List(const T *arr, int n)
{
    time_t t_time = time(nullptr);
    for(int i = 0; i < n; i++)
    {
        if (!(*(arr + i)))
            throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        push_back(*(arr + i));
    }
}

template<typename T>
List<T>::List(std::initializer_list<T> lst)
{
    for(typename std::initializer_list<T>::iterator it = lst.begin(); it < lst.end(); it++)
    {
        push_back(*it);
    }
}

template<typename T>
List<T>::List(Iterator<T> &beg, Iterator<T> &end)
{
    Iterator<T> it(beg);
    for(; it != end; it++)
    {
        push_back(*it);
    }
}

template<typename T>
List<T>::List(List<T>&& lst)
{
    this->move(lst);
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
bool List<T>::is_empty()
{
    if (head == nullptr)
        return true;
    return false;
}

template<typename T>
List<T> &List<T>::operator= (std::initializer_list<T> lst)
{
    this->clear();
    for(typename std::initializer_list<T>::iterator it = lst.begin(); it < lst.end(); it++)
    {
        push_back(*it);
    }
}

template<typename T>
void List<T>::copy(const List<T> &lst)
{
    time_t t_time = time(nullptr);
    head = new Node<T>;
    if (!head)
        throw ErrorAllocMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    for (List<T>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        push_back(it.get_value());
    }
}

template<typename T>
void List<T>::move(const List<T> &lst)
{
    time_t t_time = time(nullptr);
    std::shared_ptr<Node<T>> *head = new std::shared_ptr<Node<T>>;
    if (!head)
        throw ErrorAllocMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    for (List<T>::constiterator it = lst.begin(); it != lst.end(); it++)
    {
        push_back(it.get_value());
    }
    const_cast<List<T>*>(&lst)->clear();
}

template<typename T>
List<T> &List<T>::operator= (List<T> &&lst)
{
    this->move(lst);
}

template<typename T>
void List<T>::remove(Iterator<T> it)
{
    time_t t_time = time(NULL);
    if (it.lock() == nullptr)
    {
        throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    std::weak_ptr<Node<T>> current = it.lock()->get_next();
    it.lock()->set_next(current.lock()->get_next());
    current.reset();
}

template<typename T>
void List<T>::insert(Iterator<T> it, const T& data)
{
    time_t t_time = time(nullptr);
    if (it.expired())
    {
        throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    t_time = time(NULL);
    std::shared_ptr<Node<T>> new_ptr = std::make_shared<Node<T>>(data);
    if(!new_ptr)
        throw ErrorAllocMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    std::shared_ptr<Node<T>> next = it.get_node().lock()->get_next();
    it.get_node().lock()->set_next(new_ptr);
    new_ptr->set_next(next);
}

template<typename T>
void List<T>::push_front(const T &data)
{
    time_t t_time = time(nullptr);
   // Создаём новый узел для значения
   // Если произойдёт исключение, контейнер не пострадает
    Node<T> *node = new Node<T>(data);
    if (!node)
        throw ErrorAllocMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
   // Новый узел привязывается к старому головному элементу
    node->ptr = head;
   // Новый узел сам становится головным элементом
    head = (std::shared_ptr<Node<T>>)node;
}

template<typename T>
void List<T>::push_back(const T &data)
{
    time_t t_time = time(nullptr);
    Node<T> *node = new Node<T>(data);
    if (!node)
        throw ErrorAllocMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (head == nullptr)
    {
        node->ptr = head;
        head = (std::shared_ptr<Node<T>>)node;
    }
    else
    {
        std::shared_ptr<Node<T>> curr = head;
        while(curr)
        {

            if (curr->ptr == nullptr)
                break;
            curr = curr->ptr;
        }
        curr->ptr = (std::shared_ptr<Node<T>>)node;

    }
}

template<typename T>
Iterator<T> List<T>::begin() {return iterator(head);};

template<typename T>
Iterator<T> List<T>::end() {return iterator();};

template<typename T>
ConstIterator<T> List<T>::begin() const {return iterator(head);};

template<typename T>
ConstIterator<T> List<T>::end() const {return iterator();};

template<typename T>
ConstIterator<T> List<T>::cbegin() const{return constiterator(head);};

template<typename T>
ConstIterator<T> List<T>::cend() const{return constiterator();};

template<typename T>
void List<T>::pop_front()
{
    time_t t_time = time(nullptr);
    if(head)
    { // Если список не пуст:
        // Сохраняем указатель на второй узел, который станет новым головным элементом
        std::shared_ptr<Node<T>> newHead = head->ptr;

        // Освобождаем память, выделенную для удаляемого головного элемента
        //delete head;

        // Назначаем новый головной элемент
        head = newHead;
    }
    throw ErrorEmpty(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template<typename T>
size_t List<T>::size()
{
    size_t s = 0;

    for(std::shared_ptr<Node<T>> n = head; n != NULL; n = n->ptr)
    {
        ++s;
    }

    return s;

}

template<typename T>
void List<T>::clear()
{
    time_t t_time = time(nullptr);
    if (head == nullptr)
        throw ErrorEmpty(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    while(head)
    {
        pop_front();
    }
}

template<typename T>
List<T> &List<T>::operator+=(const List<T> &lst)
{
    combine(lst);
    return *this;
}

template<typename T>
List<T> &List<T>::operator+(const List<T> &lst)
{
    //создание нового списка
    combine(lst);
    return *this;
}

template<typename T>
List<T> &List<T>::combine(const List<T> &lst)
{
    List<T>::iterator it;
    std::shared_ptr<Node<T>> curr = head;
    while(curr)
    {

        if (curr->ptr == NULL)
            break;
        //std::cout << curr->field << " =field\n";
        curr = curr->ptr;
    }
    curr->ptr = lst.head;
    return *this;
}

template<typename T>
List<T> &List<T>::operator+(const T& data)
{
    push_back(data);
}

template<typename T>
List<T> &List<T>::operator+=(const T& data)
{
    push_back(data);
}

#endif // LIST__H
