#ifndef M_EXCEPTION__H
#define M_EXCEPTION__H

List_Exception::List_Exception(std::string filename, std::string classname, int line, const char *time,
                     std::string info)
{
    m_error = "\nFile name: " + filename + "\nClass: " + classname +
            "\nLine#: " + std::to_string(line) +
            "\nTime: " + time + "Info: " + info;
}

const char* List_Exception::what() const noexcept{return m_error.c_str();};

#endif // M_EXCEPTION__H
