#include"RDET_FAT.h"

RDET_FAT::RDET_FAT(){}
RDET_FAT::~RDET_FAT(){}
RDET_FAT::RDET_FAT(const RDET_FAT &rdet_fat_entry){}
RDET_FAT::RDET_FAT(const std::vector<uint8_t> &rdet_fat_entry){}
RDET_FAT& RDET_FAT::operator=(const RDET_FAT &rdet_fat_entry){
    return *this;
}

void RDET_FAT::set_full_name(std::string fname){
    this->full_name = fname;
}