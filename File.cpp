#include"File.h"

File::File(){}
File::~File(){}
File::File(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_)
    :Component(name_, type_, clusterBegin, size_){}
File::File(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_, const uint32_t& rank_)
    :Component(name_, type_, clusterBegin, size_, rank_){}
void File::show(){
    cout << std::setw(this->rank*3) << "" << "|--" << this->name << endl;
    //cout << std::setw(this->rank*3) << "|-" << std::setw(2) << this->type << std::setw(15) << this->size  << std::setw(15) << this->indexClusterBegin << "   " <<this->name << endl;
}