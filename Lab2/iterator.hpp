#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include "node.hpp"
#include "list.hpp"

template<typename T>

class Iterator: public std::iterator<std::input_iterator_tag, T>
{
public:
    Iterator(void);
    Iterator(std::weak_ptr<Node<T>> node);

    // Проверка на равенство
    bool operator==(const Iterator<T>& other) const;

    // Проверка на неравенство
    bool operator!=(const Iterator<T>& other) const;

    // Получение значения текущего узла
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

    operator bool() const noexcept;

    Iterator& operator++();

    Iterator operator++(int);

    Iterator& operator+=(int val);

    Iterator& operator+(int val);

    const T& get_value() const;
    T& get_value();

    const T& get_next_value() const;
    T& get_next_value();



private:
    std::weak_ptr<Node<T>> node;
};

//при звездочка стрелочка нельзя поменять значение итератора

template<typename T>

class ConstIterator: public std::iterator<std::output_iterator_tag, T>
{
public:
    ConstIterator(void);
    ConstIterator(std::weak_ptr<Node<T>> node);

    // Проверка на равенство
    bool operator==(const ConstIterator<T>& other) const;

    // Проверка на неравенство
    bool operator!=(const ConstIterator<T>& other) const;

    // Получение значения текущего узла
    const T& operator*() const;
    const T* operator->() const;

    operator bool() const noexcept;

    ConstIterator& operator++();

    ConstIterator operator++(int);

    ConstIterator& operator+=(int val);

    ConstIterator& operator+(int val);

    const T& get_value();
    const T& get_next_value() const;


private:
    std::weak_ptr<Node<T>> node;
};
#endif // ITERATOR_HPP
