#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>
#include <string>

class List_Exception: public std::exception
{
private:
    std::string m_error;

public:
    List_Exception(std::string filename, std::string classname, int line, const char *time,
              std::string info = "Error");

    const char* what() const noexcept override;
};

class ErrorAllocMemory: public List_Exception
{
public:
    ErrorAllocMemory(std::string filename, std::string classname, int line, const char *time,
                     std::string info = "Memory alloc error"): List_Exception(filename, classname, line, time, info){};
};

class ErrorRange: public List_Exception
{
public:
    ErrorRange(std::string filename, std::string classname, int line, const char *time,
               std::string info = "Range error"): List_Exception(filename, classname, line, time, info){};
};

class ErrorIndex: public List_Exception
{
public:
    ErrorIndex(std::string filename, std::string classname, int line, const char *time,
               std::string info = "Index out of range"): List_Exception(filename, classname, line, time, info){};
};

class ErrorEmpty: public List_Exception
{
public:
    ErrorEmpty(std::string filename, std::string classname, int line, const char *time,
               std::string info = "List is empty"): List_Exception(filename, classname, line, time, info){};
};
#endif // ERRORS_HPP
