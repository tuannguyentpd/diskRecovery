#ifndef __RDET_FAT_H__
#define __RDET_FAT_H__


#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

#include"Helper.h"

class RDET_FAT{
    private:
        
    public:
        RDET_FAT();
        ~RDET_FAT();
        RDET_FAT(const RDET_FAT &rdet_fat_entry);
        RDET_FAT(const std::vector<uint8_t> &rdet_fat_entry);
        RDET_FAT& operator=(const RDET_FAT &rdet_fat_entry);
    public:
};


#endif // !__RDET_FAT_H__
