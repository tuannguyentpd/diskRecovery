#ifndef __RDET_FAT_H__
#define __RDET_FAT_H__


#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

#include"Helper.h"

class RDET_FAT{
    private:
        std::string full_name;
        std::string ext_name;
        uint8_t state_attb;
        uint8_t reserved;
        uint32_t create_time;
        uint16_t create_date;
        uint16_t last_acess_date;
        uint32_t begin_cluster;
        uint16_t last_modify_time;
        uint16_t last_update_date;
        uint32_t file_size;

    public:
        RDET_FAT();
        ~RDET_FAT();
        RDET_FAT(const RDET_FAT &rdet_fat_entry);
        RDET_FAT(const std::vector<uint8_t> &rdet_fat_entry);
        RDET_FAT& operator=(const RDET_FAT &rdet_fat_entry);
    public:
        void set_ful_name(std::string fname);
};


#endif // !__RDET_FAT_H__
