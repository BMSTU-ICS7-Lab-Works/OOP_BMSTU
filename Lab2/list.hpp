#ifndef LIST_HPP
#define LIST_HPP

#include <initializer_list>
#include <memory>
#include "iterator.hpp"
#include "iterator_.h"
#include "base.h"
#include "node.hpp"

template<typename> class Iterator;
template<typename T>

class List:public Base
{
public: 
    List();
    List(std::initializer_list<T> lst);
    List(const T *arr, int n);
    List(Iterator<T> &beg, Iterator<T> &end);
    List(List<T>&& lst);

    //копирование
    explicit List(const List<T> &lst);
    //присваивание
    List<T> &operator= (List<T> const &lst);
    List<T> &operator= (List<T> &&lst);
    List<T> &operator= (std::initializer_list<T> lst);
    void copy(const List<T> &lst);
    void move(const List<T> &lst);

    ~List();

    void pop_front();
    void push_front(const T& data);

    void remove(Iterator<T> it);
    void insert(Iterator<T> it, const T &data);

    List<T> &operator+=(const List<T> &lst);
    List<T> &operator+(const List<T> &lst);
    List<T> &combine(const List<T> &lst);

    void push_back(const T& data);
    List<T> &operator+(const T& data);
    List<T> &operator+=(const T& data);

    void clear();  
    bool is_empty();
    size_t size();

    typedef Iterator<T> iterator;
    friend class Iterator<T>;

    Iterator<T> begin();
    Iterator<T> end();

    typedef ConstIterator<T> constiterator;
    friend class ConstIterator<T>;

    ConstIterator<T> begin() const;
    ConstIterator<T> end() const;

    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;
private:
    //shared_ptr совместное владение;;weak_ptr мягкое владение
    std::shared_ptr<Node<T>> head = NULL;
};

#endif // LIST_HPP
