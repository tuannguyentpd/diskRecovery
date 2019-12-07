#ifndef __PARTITION_H__
#define __PARTITION_H__

#include<iostream>
#include<vector>
#include<iomanip>

class Partition{
    private:
        uint8_t active;
        uint8_t head_begin;
        uint8_t sector_and_cylinder_begin_part_1;
        uint8_t sector_and_cylinder_begin_part_2;
        uint8_t type_fs;
        uint8_t head_end;
        uint8_t sector_and_cylinder_end_part_1;
        uint8_t sector_and_cylinder_end_part_2;
        uint32_t pos_begin_LBA;
        uint32_t num_sector_total;
        uint16_t finish_sign;
    
    private:
        void set_active(uint8_t act);
        void set_head_begin(uint8_t h_begin);
        void set_sector_and_cylinder_begin_part_1(uint32_t sec_cyl_begin);
        void set_sector_and_cylinder_begin_part_2(uint32_t sec_cyl_begin);
        void set_type_fs(uint8_t type_);
        void set_head_end(uint8_t h_end);
        void set_sector_and_cylinder_end_part_1(uint16_t sec_cyl_end);
        void set_sector_and_cylinder_end_part_2(uint16_t sec_cyl_end);
        void set_pos_begin_LBA(uint32_t pos_LBA);
        void set_num_sector_total(uint32_t no_sector_total);
        void set_finish_sign(uint16_t finish);

    public:
        bool is_active();
        uint8_t get_head_begin();
        uint8_t get_sector_begin();
        uint16_t get_cylinder_begin();
        uint8_t get_type_fs();
        uint8_t get_head_end();
        uint8_t get_sector_end();
        uint16_t get_cylinder_end();
        uint32_t get_pos_begin_LBA();
        uint32_t get_num_sector_total();
        uint16_t get_finish_sign();
        uint8_t get_active();
        bool is_finish();
        Partition(const std::vector<uint8_t> &partition_data);
        Partition(const Partition &partition);
        Partition& operator=(const Partition& partition);

    public:
        Partition();
        ~Partition();
};


#endif // !__PARTITION_H__