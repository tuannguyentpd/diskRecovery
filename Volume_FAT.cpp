#include"Volume_FAT.h"

FAT::FAT(){
    this->helper = new Helper;
}
FAT::~FAT(){
    delete this->helper;
}

FAT::FAT(const FAT &fat){
    this->helper = new Helper;
    int i;
    this->pos_begin_LBA = fat.pos_begin_LBA;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = fat.jump_instruction[i];
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = fat.OEM_ID[i];
    }
    this->bytes_per_sector = fat.bytes_per_sector;
    this->sectors_per_cluster = fat.sectors_per_cluster;
    this->sectors_before_FAT_table = fat.sectors_before_FAT_table;
    this->num_FAT_table = fat.num_FAT_table;
    this->entries_of_RDET = fat.entries_of_RDET;
    this->sectors_of_volume = fat.sectors_of_volume;
    this->volume_signature = fat.volume_signature;
    this->sectors_of_FAT = fat.sectors_of_FAT;
    this->sectors_per_track = fat.sectors_per_track;
    this->number_of_heads = fat.number_of_heads;
    this->distance_vol_describe_to_vol_begin = fat.distance_vol_describe_to_vol_begin;
    this->volume_size = fat.volume_size;
    this->disk_physical_signature = fat.disk_physical_signature;
    this->OS_signature = fat.OS_signature;
    this->volume_serial_number = fat.volume_serial_number;
    this->volume_label = fat.volume_label;
    for (i=0;i<8;++i){
        this->FAT_type[i] = fat.FAT_type[i];
    }
    this->end_sector_marker = fat.end_sector_marker;
}
FAT::FAT(const std::vector<uint8_t> &fat_boot_data){
    this->helper = new Helper;
    this->set_attrs_from_boot_sector(fat_boot_data);
}
FAT::FAT(std::ifstream &f, const uint32_t &pos_LBA){
    this->helper = new Helper;
    this->pos_begin_LBA = pos_LBA;
    std::vector<char> ntfs_boot_data(512);
    this->helper->dump_sector(f, ntfs_boot_data, this->pos_begin_LBA);
    std::vector<uint8_t> boot_sector(512);
    for (int i=0;i<512;++i)
        boot_sector[i] = ntfs_boot_data[i];
    this->set_attrs_from_boot_sector(boot_sector);
}
FAT& FAT::operator=(const FAT &fat){
    this->helper = new Helper;
    int i;
    this->pos_begin_LBA = fat.pos_begin_LBA;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = fat.jump_instruction[i];
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = fat.OEM_ID[i];
    }
    this->bytes_per_sector = fat.bytes_per_sector;
    this->sectors_per_cluster = fat.sectors_per_cluster;
    this->sectors_before_FAT_table = fat.sectors_before_FAT_table;
    this->num_FAT_table = fat.num_FAT_table;
    this->entries_of_RDET = fat.entries_of_RDET;
    this->sectors_of_volume = fat.sectors_of_volume;
    this->volume_signature = fat.volume_signature;
    this->sectors_of_FAT = fat.sectors_of_FAT;
    this->sectors_per_track = fat.sectors_per_track;
    this->number_of_heads = fat.number_of_heads;
    this->distance_vol_describe_to_vol_begin = fat.distance_vol_describe_to_vol_begin;
    this->volume_size = fat.volume_size;
    this->disk_physical_signature = fat.disk_physical_signature;
    this->OS_signature = fat.OS_signature;
    this->volume_serial_number = fat.volume_serial_number;
    this->volume_label = fat.volume_label;
    for (i=0;i<8;++i){
        this->FAT_type[i] = fat.FAT_type[i];
    }
    this->end_sector_marker = fat.end_sector_marker;

    return *this;
}

std::string FAT::get_OEMID(){
    std::string result = "";
    for (int i=0;i<8;++i){
        result += this->OEM_ID[i];
    }
    return result;
}
uint32_t FAT::get_pos_begin_LBA(){
    return this->pos_begin_LBA;
}
uint16_t FAT::get_bytes_per_sector(){
    return this->bytes_per_sector;
}
uint8_t FAT::get_sectors_per_cluster(){
    return this->sectors_per_cluster;
}
uint16_t FAT::get_sectors_before_FAT_table(){
    return this->sectors_before_FAT_table;
}
uint8_t FAT::get_num_FAT_table(){
    return this->num_FAT_table;
}
uint16_t FAT::get_entries_of_RDET(){
    return this->entries_of_RDET;
}
uint16_t FAT::get_sectors_of_volume(){
    return sectors_of_volume;
}
uint8_t FAT::get_volume_signature(){
    return this->volume_signature;
}
uint16_t FAT::get_sectors_of_FAT(){
    return sectors_of_FAT;
}
uint16_t FAT::get_sectors_per_track(){
    return this->sectors_per_track;
}
uint16_t FAT::get_number_of_heads(){
    return this->number_of_heads;
}
uint32_t FAT::get_distance_vol_describe_to_vol_begin(){
    return this->distance_vol_describe_to_vol_begin;
}
uint32_t FAT::get_volume_size(){
    return volume_size;
}
uint8_t FAT::get_disk_physical_signature(){
    return this->disk_physical_signature;
}
uint8_t FAT::get_OS_signature(){
    return this->OS_signature;
}
uint32_t FAT::get_volume_serial_number(){
    return volume_serial_number;
}
char FAT::get_volume_label(){
    return volume_label;
}
std::string FAT::get_FAT_type(){
    std::string res = "";
    for (int i=0;i<8;++i){
        res += this->FAT_type[i];
    }
    return res;
}
uint16_t FAT::get_end_sector_marker(){
    return this->end_sector_marker;
}
uint32_t FAT::get_RDET_size() //sector
{
    return (this->get_entries_of_RDET()*32)/this->get_bytes_per_sector();
}
uint32_t FAT::get_begin_sector_RDET(){
    return this->get_sectors_before_FAT_table()+this->get_sectors_of_FAT()*this->get_num_FAT_table();
}
uint32_t FAT::get_begin_sector_FAT_table(){
    return this->get_sectors_before_FAT_table();
}
uint32_t FAT::get_begin_sector_data_area(){
    return this->get_begin_sector_RDET()+this->get_RDET_size();
}


void FAT::show_volume_info(){
    std::cout << std::setw(50) << std::setfill(' ') << std::left << "OEM ID:" << this->get_OEMID() << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << "Volume label:" << this->get_volume_label() << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << "FAT type:" << this->get_FAT_type() << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::hex << "Volume Serial Number:" << (int)(this->get_volume_serial_number()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Bytes Per sector:" << int(this->get_bytes_per_sector()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sectors Per Cluster:" << int(this->get_sectors_per_cluster()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sectors Per Track:" << int(this->get_sectors_per_track()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Number Of Heads:" << int(this->get_number_of_heads()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Distance_vol_describe_to_vol_begin:" << int(this->get_distance_vol_describe_to_vol_begin()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Volume size:" << int(this->get_volume_size()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sectors of FAT:" << int(this->get_sectors_of_FAT()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sector of volume:" << int(this->get_sectors_of_volume()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sector before FAT table:" << int(this->get_sectors_before_FAT_table()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Number of FAT tables:" << int(this->get_num_FAT_table()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Entries of RDET:" << int(this->get_entries_of_RDET()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "RDET size:" << int(this->get_RDET_size()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Begin sector of FAT table:" << int(this->get_begin_sector_FAT_table()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Begin sector of RDET:" << int(this->get_begin_sector_RDET()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Begin sector of data area:" << int(this->get_begin_sector_data_area()) << std::endl;
}
void FAT::set_attrs_from_boot_sector(const std::vector<uint8_t> &fat_boot_data){
    int i;
    if (fat_boot_data.size() != 512) return;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = char(fat_boot_data[i]);
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = char(fat_boot_data[3+i]);
    }
    this->bytes_per_sector = uint16_t((fat_boot_data[12]<<8)|fat_boot_data[11]);
    this->sectors_per_cluster = uint8_t(fat_boot_data[13]);
    this->sectors_before_FAT_table = uint16_t((fat_boot_data[15]<<8)|fat_boot_data[14]);
    this->num_FAT_table = uint8_t(fat_boot_data[16]);
    this->entries_of_RDET = uint16_t((fat_boot_data[18]<<8)|fat_boot_data[17]);
    this->sectors_of_volume = uint16_t((fat_boot_data[20]<<8)|fat_boot_data[19]);
    this->volume_signature = uint8_t(fat_boot_data[21]);
    this->sectors_of_FAT = uint16_t((fat_boot_data[23]<<8)|fat_boot_data[22]);
    this->sectors_per_track = uint16_t((fat_boot_data[25]<<8)|fat_boot_data[24]);
    this->number_of_heads = uint16_t((fat_boot_data[27]<<8)|fat_boot_data[26]);
    this->distance_vol_describe_to_vol_begin = uint32_t((((((fat_boot_data[31]<<8)|fat_boot_data[30])<<8)|fat_boot_data[29])<<8)|fat_boot_data[28]);
    this->volume_size = uint32_t((((((fat_boot_data[35]<<8)|fat_boot_data[34])<<8)|fat_boot_data[33])<<8)|fat_boot_data[32]);
    this->disk_physical_signature = uint8_t(fat_boot_data[36]);
    this->OS_signature = uint8_t(fat_boot_data[38]);
    this->volume_serial_number = uint32_t((((((fat_boot_data[42]<<8)|fat_boot_data[41])<<8)|fat_boot_data[40])<<8)|fat_boot_data[39]);
    this->volume_label = char(fat_boot_data[43]);
    for (i=0;i<8;++i){
        this->FAT_type[i] = char(fat_boot_data[54+i]);
    }
    this->end_sector_marker = uint16_t((fat_boot_data[510]<<8)|fat_boot_data[511]);
}