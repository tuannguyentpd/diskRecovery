#ifndef __TREEDIR_H__
#define __TREEDIR_H__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>

#include "Helper.h"

#include"Component.h"
#include "File.h"

using namespace std;


class TreeDIR: public Component {
    private:
        std::vector<Component*> files;
        uint32_t numItems;
        Helper *helper;
    public:
        TreeDIR();
        ~TreeDIR();
        TreeDIR(const uint32_t&);
        TreeDIR(const vector<char> &rDET);
        TreeDIR(const string &name, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_);
        TreeDIR(const string &name, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_, const uint32_t& rank_, std::ifstream &f, const uint32_t& idxSector);
    public:
        void show();
        void add(Component*);
        bool vectorIsEmpty(const vector<char>&);
        int getNumItems();
};

#endif