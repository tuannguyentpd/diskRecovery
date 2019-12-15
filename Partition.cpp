#include"Partition.h"

Partition::Partition(){}
Partition::~Partition(){}

bool Partition::is_active(){
    if (this->active == 0)
        return false;
    else
        return true;
}
uint8_t Partition::get_head_begin(){
    return this->head_begin;
}
uint8_t Partition::get_sector_begin(){
    uint8_t temp = this->sector_and_cylinder_begin_part_1<<2;
    return temp>>2;
}
uint16_t Partition::get_cylinder_begin(){
    uint16_t temp = this->sector_and_cylinder_begin_part_1>>6;
    return (temp<<8)+this->sector_and_cylinder_begin_part_2;
}
uint8_t Partition::get_type_fs(){
    return this->type_fs;
}
uint8_t Partition::get_head_end(){
    return this->head_end;
}
uint8_t Partition::get_sector_end(){
    uint8_t temp = this->sector_and_cylinder_end_part_1<<2;
    return temp>>2;
}
uint16_t Partition::get_cylinder_end(){
    uint16_t temp = this->sector_and_cylinder_end_part_1>>6;
    return (temp<<8)+this->sector_and_cylinder_end_part_2;
}
uint32_t Partition::get_pos_begin_LBA(){
    return this->pos_begin_LBA;
}
uint32_t Partition::get_num_sector_total(){
    return this->num_sector_total;
}
uint16_t Partition::get_finish_sign(){
    return this->finish_sign;
}
uint8_t Partition::get_active(){
    return this->active;
}
bool Partition::is_finish(){
    return this->finish_sign == 21930; //==0x55aa
}
Partition::Partition(const std::vector<uint8_t> &partition_data){
    if (partition_data.size() != 18) return;
    this->active = uint8_t(partition_data[0]);
    this->head_begin = uint8_t(partition_data[1]);
    this->sector_and_cylinder_begin_part_1 = uint8_t(partition_data[2]);
    this->sector_and_cylinder_begin_part_2 = uint8_t(partition_data[3]);
    this->type_fs = uint8_t(partition_data[4]);
    this->head_end = uint8_t(partition_data[5]);
    this->sector_and_cylinder_end_part_1 = uint8_t(partition_data[6]);
    this->sector_and_cylinder_end_part_2 = uint8_t(partition_data[7]);
    this->pos_begin_LBA = uint32_t((((((partition_data[11]<<8)|partition_data[10])<<8)|partition_data[9])<<8)|partition_data[8]);
    this->num_sector_total = uint32_t((((((partition_data[15]<<8)|partition_data[14])<<8)|partition_data[13])<<8)|partition_data[12]);
    this-> finish_sign = uint16_t((partition_data[16]<<8)|partition_data[17]);
}
Partition::Partition(const Partition &partition){
    this->active = partition.active;
    this->head_begin = partition.head_begin;
    this->sector_and_cylinder_begin_part_1 = partition.sector_and_cylinder_begin_part_1;
    this->sector_and_cylinder_begin_part_2 = partition.sector_and_cylinder_begin_part_2;
    this->type_fs = partition.type_fs;
    this->head_end = partition.head_end;
    this->sector_and_cylinder_end_part_1 = partition.sector_and_cylinder_end_part_1;
    this->sector_and_cylinder_end_part_2 = partition.sector_and_cylinder_end_part_2;
    this->pos_begin_LBA = partition.pos_begin_LBA;
    this->num_sector_total = partition.num_sector_total;
    this->finish_sign = partition.finish_sign;
}
Partition& Partition::operator=(const Partition& partition){
    this->active = partition.active;
    this->head_begin = partition.head_begin;
    this->sector_and_cylinder_begin_part_1 = partition.sector_and_cylinder_begin_part_1;
    this->sector_and_cylinder_begin_part_2 = partition.sector_and_cylinder_begin_part_2;
    this->type_fs = partition.type_fs;
    this->head_end = partition.head_end;
    this->sector_and_cylinder_end_part_1 = partition.sector_and_cylinder_end_part_1;
    this->sector_and_cylinder_end_part_2 = partition.sector_and_cylinder_end_part_2;
    this->pos_begin_LBA = partition.pos_begin_LBA;
    this->num_sector_total = partition.num_sector_total;
    this->finish_sign = partition.finish_sign;            
}

void Partition::set_active(uint8_t act){
    this->active = act;
}
void Partition::set_head_begin(uint8_t h_begin){
    this->head_begin = h_begin;
}
void Partition::set_sector_and_cylinder_begin_part_1(uint32_t sec_cyl_begin){
    this->sector_and_cylinder_begin_part_1 = sec_cyl_begin;
}
void Partition::set_sector_and_cylinder_begin_part_2(uint32_t sec_cyl_begin){
    this->sector_and_cylinder_begin_part_2 = sec_cyl_begin;
}
void Partition::set_type_fs(uint8_t type_){
    this->type_fs = type_;
}
void Partition::set_head_end(uint8_t h_end){
    this->head_end = h_end;
}
void Partition::set_sector_and_cylinder_end_part_1(uint16_t sec_cyl_end){
    this->sector_and_cylinder_end_part_1 = sec_cyl_end;
}
void Partition::set_sector_and_cylinder_end_part_2(uint16_t sec_cyl_end){
    this->sector_and_cylinder_end_part_2 = sec_cyl_end;
}
void Partition::set_pos_begin_LBA(uint32_t pos_LBA){
    this->pos_begin_LBA = pos_LBA;
}
void Partition::set_num_sector_total(uint32_t no_sector_total){
    this->num_sector_total = no_sector_total;
}
void Partition::set_finish_sign(uint16_t finish){
    this->finish_sign = finish;
}