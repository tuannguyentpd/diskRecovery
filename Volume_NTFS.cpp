#include"Volume_NTFS.h"

NTFS::NTFS(){}
NTFS::~NTFS(){}

NTFS::NTFS(const std::vector<uint8_t> &ntfs_boot_data){
    this->set_attrs_from_boot_sector(ntfs_boot_data);
}
NTFS::NTFS(const NTFS &ntfs){
    int i;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = ntfs.jump_instruction[i];
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = ntfs.OEM_ID[i];
    }
    this->bytes_per_sector = ntfs.bytes_per_sector;
    this->sectors_per_cluster = ntfs.sectors_per_cluster;
    this->reserved_sector = ntfs.reserved_sector;
    this->media_descripter = ntfs.media_descripter;
    this->sectors_per_track = ntfs.sectors_per_track;
    this->number_of_heads = ntfs.number_of_heads;
    this->hidden_sectors = 
    this->total_sectors = 
    this->logical_cluster_number_MFT = ntfs.logical_cluster_number_MFT;
    this->logical_cluster_number_MFTMirr = ntfs.logical_cluster_number_MFTMirr;
    this->clusters_per_file_record_segment = ntfs.clusters_per_file_record_segment;
    this->cluster_per_index_buffer = ntfs.cluster_per_index_buffer;
    this->volume_serial_number = ntfs.volume_serial_number;
    for (i=0;i<4;++i){
        this->checksum[i] = ntfs.checksum[i];
    }
    this->end_sector_marker = ntfs.end_sector_marker;
}
NTFS::NTFS(std::ifstream &f, const uint32_t &pos_LBA){
    this->pos_begin_LBA = pos_LBA;
    std::vector<char> ntfs_boot_data(512);
    dump_sector(f, ntfs_boot_data, this->pos_begin_LBA);
    std::vector<uint8_t> boot_sector(512);
    for (int i=0;i<512;++i)
        boot_sector[i] = ntfs_boot_data[i];
    this->set_attrs_from_boot_sector(boot_sector);
}
NTFS& NTFS::operator=(const NTFS &ntfs){
    int i;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = ntfs.jump_instruction[i];
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = ntfs.OEM_ID[i];
    }
    this->bytes_per_sector = ntfs.bytes_per_sector;
    this->sectors_per_cluster = ntfs.sectors_per_cluster;
    this->reserved_sector = ntfs.reserved_sector;
    this->media_descripter = ntfs.media_descripter;
    this->sectors_per_track = ntfs.sectors_per_track;
    this->number_of_heads = ntfs.number_of_heads;
    this->hidden_sectors = 
    this->total_sectors = 
    this->logical_cluster_number_MFT = ntfs.logical_cluster_number_MFT;
    this->logical_cluster_number_MFTMirr = ntfs.logical_cluster_number_MFTMirr;
    this->clusters_per_file_record_segment = ntfs.clusters_per_file_record_segment;
    this->cluster_per_index_buffer = ntfs.cluster_per_index_buffer;
    this->volume_serial_number = ntfs.volume_serial_number;
    for (i=0;i<4;++i){
        this->checksum[i] = ntfs.checksum[i];
    }
    this->end_sector_marker = ntfs.end_sector_marker;
}

std::string NTFS::get_OEMID(){
    std::string result = "";
    for (int i=0;i<8;++i){
        result += this->OEM_ID[i];
    }
    return result;
}
uint32_t NTFS::get_pos_begin_LBA(){
    return this->pos_begin_LBA;
}
uint16_t NTFS::get_bytes_per_sector(){
    return this->bytes_per_sector;
}
uint8_t NTFS::get_sectors_per_cluster(){
    return sectors_per_cluster;
}
uint16_t NTFS::get_reserved_sector(){
    return reserved_sector;
}
uint8_t NTFS::get_media_descripter(){
    return this->media_descripter;
}
uint16_t NTFS::get_sectors_per_track(){
    return sectors_per_track;
}
uint16_t NTFS::get_number_of_heads(){
    return number_of_heads;
}
uint32_t NTFS::get_hidden_sectors(){
    return hidden_sectors;
}
long long NTFS::get_total_sectors(){
    return this->total_sectors;
}
long long NTFS::get_logical_cluster_number_MFT(){
    return this->logical_cluster_number_MFT;
}
long long NTFS::get_logical_cluster_number_MFTMirr(){
    return this->logical_cluster_number_MFTMirr;
}
uint32_t NTFS::get_clusters_per_file_record_segment(){
    return clusters_per_file_record_segment;
}
uint8_t NTFS::get_cluster_per_index_buffer(){
    return cluster_per_index_buffer;
}
long long NTFS::get_volume_serial_number(){
    return volume_serial_number;
}
uint16_t NTFS::get_end_sector_marker(){
    return this->end_sector_marker;
}

void NTFS::show_volume_info(){
    std::cout << std::setw(50) << std::setfill(' ') << "OEM ID:" << this->get_OEMID() << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::hex << "Volume Serial Number:" << (long long)(this->get_volume_serial_number()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Bytes Per sector:" << int(this->get_bytes_per_sector()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sectors Per Cluster:" << int(this->get_sectors_per_cluster()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Media Descripts:" << int(this->get_media_descripter()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Sectors Per Track:" << int(this->get_sectors_per_track()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Number Of Heads:" << int(this->get_number_of_heads()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Total Sectors:" << (long long)(this->get_total_sectors()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Logical Cluster Number for the file $MFT:" << (long long)(this->get_logical_cluster_number_MFT()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Logical Cluster Number for the file $MFTMirr:" << (long long)(this->get_logical_cluster_number_MFTMirr()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Clusters Per File Record Segment:" << int(this->get_clusters_per_file_record_segment()) << std::endl;
    std::cout << std::setw(50) << std::setfill(' ') << std::dec << "Clusters Per Index Buffer:" << int(this->get_cluster_per_index_buffer()) << std::endl;
}

void NTFS::set_attrs_from_boot_sector(const std::vector<uint8_t> &ntfs_boot_data){
    int i;
    if (ntfs_boot_data.size() != 512) return;
    for (i=0;i<3;++i){
        this->jump_instruction[i] = char(ntfs_boot_data[i]);
    }
    for (i=0;i<8;++i){
        this->OEM_ID[i] = char(ntfs_boot_data[3+i]);
    }
    this->bytes_per_sector = uint16_t((ntfs_boot_data[12]<<8)+ntfs_boot_data[11]);
    this->sectors_per_cluster = uint8_t(ntfs_boot_data[13]);
    this->reserved_sector = uint16_t((ntfs_boot_data[15]<<8)+ntfs_boot_data[14]);
    this->media_descripter = uint8_t(ntfs_boot_data[21]);
    this->sectors_per_track = uint16_t((ntfs_boot_data[25]<<8)+ntfs_boot_data[24]);
    this->number_of_heads = uint16_t((ntfs_boot_data[27]<<8)+ntfs_boot_data[26]);
    this->hidden_sectors = uint32_t((((((ntfs_boot_data[31]<<8)+ntfs_boot_data[30])<<8)+ntfs_boot_data[29])<<8)+ntfs_boot_data[28]);
    this->total_sectors = (long long)((((((((((ntfs_boot_data[47]<<8)+ntfs_boot_data[46])<<8)+ntfs_boot_data[45])<<8)+ntfs_boot_data[44]<<8)+ntfs_boot_data[43]<<8)+ntfs_boot_data[42]<<8)+ntfs_boot_data[41]<<8)+ntfs_boot_data[40]);
    this->logical_cluster_number_MFT = (long long)((((((((((ntfs_boot_data[55]<<8)+ntfs_boot_data[54])<<8)+ntfs_boot_data[53])<<8)+ntfs_boot_data[52]<<8)+ntfs_boot_data[51]<<8)+ntfs_boot_data[50]<<8)+ntfs_boot_data[49]<<8)+ntfs_boot_data[48]);
    this->logical_cluster_number_MFTMirr = (long long)((((((((((ntfs_boot_data[63]<<8)+ntfs_boot_data[62])<<8)+ntfs_boot_data[61])<<8)+ntfs_boot_data[60]<<8)+ntfs_boot_data[59]<<8)+ntfs_boot_data[58]<<8)+ntfs_boot_data[57]<<8)+ntfs_boot_data[56]);
    this->clusters_per_file_record_segment = uint32_t((((((ntfs_boot_data[67]<<8)+ntfs_boot_data[66])<<8)+ntfs_boot_data[65])<<8)+ntfs_boot_data[64]);
    this->cluster_per_index_buffer = uint8_t(ntfs_boot_data[68]);
    this->volume_serial_number = (long long)((((((((((ntfs_boot_data[79]<<8)+ntfs_boot_data[78])<<8)+ntfs_boot_data[77])<<8)+ntfs_boot_data[76]<<8)+ntfs_boot_data[75]<<8)+ntfs_boot_data[74]<<8)+ntfs_boot_data[73]<<8)+ntfs_boot_data[72]);
    for (i=0;i<4;++i){
        this->checksum[i] = char(ntfs_boot_data[80+i]);
    }
    this->end_sector_marker = uint16_t((ntfs_boot_data[510]<<8)+ntfs_boot_data[511]);
}