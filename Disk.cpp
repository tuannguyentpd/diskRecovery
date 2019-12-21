#include"Disk.h"


std::vector<uint8_t> code{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0f, 0x65, 0x66, 0x81, 0x85, 0x8a, 0x93, 0xa0,0xa3, 0xa8, 0xbe, 0xc3, 0xdb, 0xec, 0xf9, 0xfa, 0xff};
std::vector<std::string> type_fs{"DOS 12-bit FAT", "XENIX root", "EXNIX /usr", "DOS 3.0+ 16bit FAT", "Extended Partition", "DOS 3.1+ 16bit FAT", "OS/2 IFS", "OS/2 (v1.0-1.3 only", "AIX data partition", "OS2 Boot Manager", "WIN95 FAT32", "WIN92 FAT32, LBA mapped", "Extended Partition - BIOS", "Novell Netware 386", "Novell Netware SMS", "MINIX", "Linux extended", "Linux kernel", "Hidden Linux native", "Laptop hibernation", "HP volume Expansion", "Mac OS-X", "Solaris 8 boot", "Hidden Linux swap", "CP/M", "SkyOS SkyFS", "pCache", "Bochs", "Xenix Bad Block table"};

Disk::Disk(){
    this->helper = new Helper;
}
Disk::~Disk(){
    delete this->helper;
}

Partition* Disk::get_partition_entry(const int &idx){
    if (idx<0 || idx>3) return this->partitions_entry[0];
    return this->partitions_entry[idx];
}

void Disk::show_partition_info(){
    std::cout << "      Partition type      | Active boot |     Starting loc     |       Ending loc     | Relative sectors | Number of sector" << std::endl;
    std::cout << "                          |             | Cyl     Head     Sec | Cyl     Head     Sec |                  |                 " << std::endl;
    std::cout << "===========================================================================================================================" << std::endl;

    Partition *par;
    for (int i=0;i<4;++i){
        par = this->get_partition_entry(i);
        if (this->code_mapping_type_fs[par->get_type_fs()].length() != 0)
            std::cout << std::left << std::setw(26) << std::setfill(' ') << this->code_mapping_type_fs[par->get_type_fs()] << "| ";
        else
        {
            std::cout << std::left << std::setw(26) << std::setfill(' ') << "Unknown" << "| ";
        }
        if (par->is_active())
            std::cout << std::setw(11) << "Yes" << " | ";
        else
        {
            std::cout << std::setw(11) << "No" << " | ";
        }
        std::cout << std::setw(7) << std::dec << int(par->get_cylinder_begin()) << " ";
        std::cout << std::setw(8) << std::dec << int(par->get_head_begin()) << " ";
        std::cout << std::setw(3) << std::dec << int(par->get_sector_begin()) << " | ";
        std::cout << std::setw(7) << std::dec << int(par->get_cylinder_end()) << " ";
        std::cout << std::setw(8) << std::dec << int(par->get_head_end()) << " ";
        std::cout << std::setw(3) << std::dec << int(par->get_sector_end()) << " | ";
        std::cout << std::setw(16) << std::dec << int(par->get_pos_begin_LBA()) << " | ";
        std::cout << std::setw(16) << std::dec << int(par->get_num_sector_total()) << std::endl;
    }
}

Disk::Disk(const std::vector<char> &master_boot_record_data){
    this->helper = new Helper;
    int i = 0;
    for (i=0;i<440;++i){
        this->code_erea.push_back(master_boot_record_data[i]);
    }
    this->disk_signature.push_back(master_boot_record_data[440]);
    this->disk_signature.push_back(master_boot_record_data[441]);
    this->disk_signature.push_back(master_boot_record_data[442]);
    this->disk_signature.push_back(master_boot_record_data[443]);
    this->null_area.push_back(master_boot_record_data[444]);
    this->null_area.push_back(master_boot_record_data[445]);
    i = 446;
    std::vector<uint8_t> partition_data(18);
    for (;i<464;++i){
        partition_data[i-446] = master_boot_record_data[i];
    }
    this->partitions_entry.push_back(new Partition(partition_data));
    for (i=i-2;i<480;++i){
        partition_data[i-462] = master_boot_record_data[i];
    }
    this->partitions_entry.push_back(new Partition(partition_data));
    for (i=i-2;i<496;++i){
        partition_data[i-478] = master_boot_record_data[i];
    }
    this->partitions_entry.push_back(new Partition(partition_data));
    for (i=i-2;i<512;++i){
        partition_data[i-494] = master_boot_record_data[i];
    }
    this->partitions_entry.push_back(new Partition(partition_data));
    this->MBR_signature.push_back(master_boot_record_data[510]);
    this->MBR_signature.push_back(master_boot_record_data[511]);

    this->helper->set_code_mapping_type_fs(this->code_mapping_type_fs, code, type_fs);
}