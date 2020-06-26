#include "main.h"
#include <iostream>
#include "m_exception_.h"

using namespace std;

int main()
{
    List<char> lst{'a', 'e', 'o'};
    char *arr = new char [3];
    *arr = 'd';
    *(arr + 1) = 'o';
    *(arr + 2) = 'p';
    cout << lst.is_empty() << '\n';
    lst.push_back('a');
    lst.push_front('o');
    lst.push_back('e');
    cout << lst.size() << '\n';
    cout << lst.is_empty() << '\n';
    List<char> lst2;
    lst2.move(lst);
    //cout << lst.get_value();
    List<char>::iterator it1;
    it1 = lst.begin();
    List<char>::iterator it2;
    it2 = lst.end();
    bool who = it2;
    cout << who << " oi" << std::endl;
    //List<char> lst2(it1, it2);
    //cout << it2.node.expired() << "\n";
    //cout << *(it2+2) << " it\n";
    for (List<char>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        *it = 'b';
        cout << *it;
    }
    List<char> lst3;
    lst3.clear();
    return 0;
}

