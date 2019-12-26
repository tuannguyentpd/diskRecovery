// foo.cpp
// g++ -o foo.so foo.h -std=c++11 -fPIC -shared -Wall -Wextra `python3.6-config --includes --libs` -lboost_python3

#include"foo.h"

A::A(int i):m_i{i} { }

int A::get_i() const {
    return this->m_i;
}