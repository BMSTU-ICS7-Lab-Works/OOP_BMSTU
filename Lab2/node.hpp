#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

template<typename> class List;
template<typename> class Iterator;
template<typename T>


class Node
{
public:
    Node() : ptr(NULL){}
    Node(const T& data):field(data), ptr(NULL){}
    void set_next(std::shared_ptr<Node<T>> elem);
    void set_next_null();
    std::shared_ptr<Node<T>> get_next();
private:
    T field;
    std::shared_ptr<Node<T>> ptr;
    friend class List<T>;
    friend class Iterator<T>;
};

#endif // NODE_HPP
