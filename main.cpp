#include"Helper.h"

#include"Disk.h"
#include"Volume_NTFS.h"



int main()
{
    int n = 512;

    std::ifstream file("/dev/sda", std::ios::binary|std::ios::in);
    if (!file) {
        std::cerr << "Couldn't open /dev/sdb. Exiting..." << '\n';
        return 1;
    }

    std::vector<char> randomBytes(n);
    dump_sector(file, randomBytes, 0);
    // show_hex_data_dump(randomBytes, 0);
    // std::cout << std::endl; 
    // std::cout << std::endl;
    // std::cout << std::endl;


    Disk* disk = new Disk(randomBytes);
    disk->show_partition_info();

    Partition *partition_1 = disk->get_partition_entry(0);
    int boot_record_idx_par1 = partition_1->get_pos_begin_LBA();
    dump_sector(file, randomBytes, boot_record_idx_par1);
    //show_hex_data_dump(randomBytes, boot_record_idx_par1);
    //std::cout << std::endl;

    std::vector<uint8_t> ntfs_data(n);
    uint8_t temp;
    for (int i=0;i<512;++i){
        ntfs_data[i] = uint8_t(int(randomBytes[i]));
    }
    NTFS* ntfs = new NTFS(ntfs_data);
    ntfs->show_volume_info();
    std::cout <<std::endl;

    /*
    // Vi tri LBA cua MFT vaf MFTMirr la vi tri LBA cua partition -> thuc te: phai + pos_sector_LBA_partition
    //Lay sector dau cua MFT - tu vi tri LBA cua cluster MFT
    std::vector<char> MFT(512);
    dump_random_data(file, MFT,boot_record_idx_par1+ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster(),512);
    show_hex_data_dump(MFT, boot_record_idx_par1+ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster());
    //Lay sector dau cua FMT - tu vi tri LBA cua cluster MFTMirr - bang copy cua MFT
    dump_random_data(file, MFT,boot_record_idx_par1+ntfs->get_logical_cluster_number_MFTMirr()*ntfs->get_sectors_per_cluster(),512);
    show_hex_data_dump(MFT, boot_record_idx_par1+ntfs->get_logical_cluster_number_MFTMirr()*ntfs->get_sectors_per_cluster());
    */


    std::vector<char> MFT(512);
    dump_random_data(file, MFT,boot_record_idx_par1+ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster(),512);
    show_hex_data_dump(MFT, boot_record_idx_par1+ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster());

    std::cout << std::endl;
    file.close();

    return 0;
}