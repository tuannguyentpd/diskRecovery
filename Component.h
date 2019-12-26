#ifndef __COMPONENT__
#define __COMPONENT__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Component {
    protected:
        std::string name;
        char type;
        uint32_t indexClusterBegin;
        uint32_t size;
        uint32_t rank;
    public:
        Component();
        ~Component();
        Component(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_);
        Component(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_, const uint32_t &rank_);
    public:
        virtual void show() = 0;
};

#endif