#include"Component.h"

Component::Component(){
    
}
Component::~Component(){

}
Component::Component(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_){
    this->name = name_;
    this->type = type_;
    this->indexClusterBegin = clusterBegin;
    this->size = size_;
}
Component::Component(const string &name_, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_, const uint32_t& rank_){
    this->name = name_;
    this->type = type_;
    this->indexClusterBegin = clusterBegin;
    this->size = size_;
    this->rank = rank_;
}