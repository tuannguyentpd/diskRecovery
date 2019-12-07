#ifndef __VOLUME_NTFS_H__
#define __VOLUME_NTFS_H__

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

#include"Helper.h"


class NTFS{
    private:
        char jump_instruction[3];
        char OEM_ID[8];       
        uint16_t bytes_per_sector;
        uint8_t sectors_per_cluster;
        uint16_t reserved_sector;
        uint8_t media_descripter;
        uint16_t sectors_per_track;
        uint16_t number_of_heads;
        uint32_t hidden_sectors;
        long long total_sectors;
        long long logical_cluster_number_MFT;
        long long logical_cluster_number_MFTMirr;
        uint32_t clusters_per_file_record_segment;
        uint8_t cluster_per_index_buffer;
        long long volume_serial_number;
        char checksum[4];
        uint16_t end_sector_marker;

    public:
        NTFS();
        ~NTFS();
        NTFS(const std::vector<uint8_t> &ntfs_boot_data);
        NTFS(const NTFS &ntfs);
        NTFS& operator=(const NTFS &ntfs);

    public:  
        std::string get_OEMID();
        uint16_t get_bytes_per_sector();
        uint8_t get_sectors_per_cluster();
        uint16_t get_reserved_sector();
        uint8_t get_media_descripter();
        uint16_t get_sectors_per_track();
        uint16_t get_number_of_heads();
        uint32_t get_hidden_sectors();
        long long get_total_sectors();
        long long get_logical_cluster_number_MFT();
        long long get_logical_cluster_number_MFTMirr();
        uint32_t get_clusters_per_file_record_segment();
        uint8_t get_cluster_per_index_buffer();
        long long get_volume_serial_number();
        uint16_t get_end_sector_marker();

        void show_volume_info();
        void show_volume_info_test();
};


#endif // !__VOLUME_NTFS_H__