#ifndef ITERATOR__H
#define ITERATOR__H

#include "node.hpp"
#include <ctime>
#include "m_exception.hpp"
#include <iostream>

template<typename T>

Iterator<T>::Iterator() { };

template<typename T>
Iterator<T>::Iterator(std::weak_ptr<Node<T>> node) : node(node) { };

template<typename T>
bool Iterator<T>::operator==(const Iterator& other) const
{
    if(this == &other)
    {
        return true;
    }
    return node.lock() == other.node.lock();
};

template<typename T>
bool Iterator<T>::operator!=(const Iterator& other) const
{
    if (this->node.expired() == true || this == &other)
        return false;
    return true;
    //return !operator==(other);
};

template<typename T>
T& Iterator<T>:: operator*()
{
    time_t t_time = time(nullptr);
    if(node.lock() == nullptr)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
const T& Iterator<T>::operator*() const
{
    time_t t_time = time(nullptr);
    if(node.lock() == nullptr)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
T* Iterator<T>::operator->()
{
    time_t t_time = time(nullptr);
    if(node.lock() == nullptr)
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return node.lock()->field;
}

template<typename T>
const T* Iterator<T>::operator->() const
{
    time_t t_time = time(nullptr);
    if(node.expired() == true)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    }
    return node.lock()->field;
}

template<typename T>
Iterator<T>::operator bool() const noexcept
{
    if (node.expired() == true)
        return false;
    else
        return true;
}

template<typename T>
Iterator<T> &Iterator<T>::operator+=(int val)
{
    Iterator it(*this);
    while (val > 0)
    {
        ++*this;
        val--;
    }
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator+(int val)
{
    Iterator it(*this);
    while (val > 0)
    {
        ++*this;
        val--;
    }
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    if(node.expired() == false)
    {
        node = node.lock()->ptr;
    } // Иначе достигнут конец списка. Здесь уместно возбудить исключение
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator it(*this);
    ++*this;
    return *this;
}

template<typename T>
const T& Iterator<T>::get_value() const
{
    time_t t_time = time(nullptr);
    if(node.expired() == true)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
T& Iterator<T>::get_value()
{
    time_t t_time = time(nullptr);
    if(node.expired() == true)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
const T& Iterator<T>::get_next_value() const
{
    return node.lock()->ptr.lock()->field;
}

template<typename T>
T& Iterator<T>::get_next_value()
{
    return node.lock()->ptr.lock()->field;
}

//const iterator
template<typename T>

ConstIterator<T>::ConstIterator() { };

template<typename T>
ConstIterator<T>::ConstIterator(std::weak_ptr<Node<T>> node) : node(node) { };

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator& other) const
{
    if(this == &other)
    {
        return true;
    }
    return node.lock() == other.node.lock();
};

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator& other) const
{
    if (this->node.expired() == true || this == &other)
        return false;
    return true;
    //return !operator==(other);
};

template<typename T>
const T& ConstIterator<T>::operator*() const
{
    time_t t_time = time(nullptr);
    if(node.lock() == nullptr)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
const T* ConstIterator<T>::operator->() const
{
    time_t t_time = time(nullptr);
    if(node.lock() != nullptr)
    {
        return node.lock()->field;
    }
    throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template<typename T>
ConstIterator<T>::operator bool() const noexcept
{
    if (node.expired() == true)
        return false;
    else
        return true;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator+=(int val)
{
    ConstIterator it(*this);
    while (val > 0)
    {
        ++*this;
        val--;
    }
    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator+(int val)
{
    ConstIterator it(*this);
    while (val > 0)
    {
        ++*this;
        val--;
    }
    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++()
{
    if(node.expired() == false)
    {
        node = node.lock()->ptr;
    } // Иначе достигнут конец списка. Здесь уместно возбудить исключение
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
    ConstIterator it(*this);
    ++*this;
    return *this;
}

template<typename T>
const T& ConstIterator<T>::get_value()
{
    time_t t_time = time(nullptr);
    if(node.expired() == true)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

template<typename T>
const T& ConstIterator<T>::get_next_value() const
{
    time_t t_time = time(nullptr);
    if(node.expired() == true)
    {
        throw ErrorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return node.lock()->field;
}

#endif // ITERATOR__H
