#ifndef BASE_H
#define BASE_H


class Base
{
public:
    virtual bool is_empty() = 0;
    virtual size_t size() = 0;
    virtual void clear() = 0;
    virtual ~Base() = default;
};

#endif // BASE_H
