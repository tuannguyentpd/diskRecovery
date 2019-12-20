#ifndef __VOLUME_FAT__
#define __VOLUME_FAT__


#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

#include"Helper.h"


class FAT{
    private:
        uint32_t pos_begin_LBA;
        char jump_instruction[3];
        char OEM_ID[8];       
        uint16_t bytes_per_sector;
        uint8_t sectors_per_cluster;
        uint16_t sectors_before_FAT_table;
        uint8_t num_FAT_table;
        uint16_t entries_of_RDET;
        uint16_t sectors_of_volume;
        uint8_t volume_signature;
        uint16_t sectors_of_FAT;
        uint16_t sectors_per_track;
        uint16_t number_of_heads;
        uint32_t distance_vol_describe_to_vol_begin;
        uint32_t volume_size;
        uint8_t disk_physical_signature;
        uint8_t OS_signature;
        uint32_t volume_serial_number;
        char volume_label;
        char FAT_type[8];
        uint16_t end_sector_marker;

    public:
        FAT();
        ~FAT();
        FAT(const FAT &fat);
        FAT(const std::vector<uint8_t> &fat_boot_data);
        FAT(std::ifstream &f, const uint32_t &pos_LBA);
        FAT& operator=(const FAT &fat);
    public:
        std::string get_OEMID();
        uint32_t get_pos_begin_LBA();
        uint16_t get_bytes_per_sector();
        uint8_t get_sectors_per_cluster();
        uint16_t get_sectors_before_FAT_table();
        uint8_t get_num_FAT_table();
        uint16_t get_entries_of_RDET();
        uint16_t get_sectors_of_volume();
        uint8_t get_volume_signature();
        uint16_t get_sectors_of_FAT();
        uint16_t get_sectors_per_track();
        uint16_t get_number_of_heads();
        uint32_t get_distance_vol_describe_to_vol_begin();
        uint32_t get_volume_size();
        uint8_t get_disk_physical_signature();
        uint8_t get_OS_signature();
        uint32_t get_volume_serial_number();
        char get_volume_label();
        std::string get_FAT_type();
        uint16_t get_end_sector_marker();

        void show_volume_info();
        void set_attrs_from_boot_sector(const std::vector<uint8_t> &fat_boot_data);
};

#endif // !__VOLUME_FAT__
