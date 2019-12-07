#ifndef __DISK_H__
#define __DISK_H__

#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

#include"Partition.h"
#include"Helper.h"


class Disk{
    private:
        std::vector<uint8_t> code_erea;
        std::vector<uint8_t> disk_signature;
        std::vector<uint8_t> null_area;
        std::vector<Partition*> partitions_entry;
        std::vector<uint8_t> MBR_signature;

    public:
        std::map<uint8_t, std::string> code_mapping_type_fs;

    public:
        Partition* get_partition_entry(const int &idx);
        void show_partition_info();

    public:
        Disk();
        ~Disk();

    public:
        Disk(const std::vector<char> &master_boot_record_data);

};


#endif // !__DISK_H__