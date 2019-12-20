#include"Helper.h"

#include"Disk.h"
#include"Volume_NTFS.h"
#include"Volume_FAT.h"



int main()
{
    int n = 512;

    std::ifstream file("/dev/sdb3", std::ios::binary|std::ios::in);
    if (!file) {
        std::cerr << "Couldn't open /dev/sdb. Exiting..." << '\n';
        return 1;
    }

    std::vector<char> randomBytes(n);
    dump_sector(file, randomBytes, 0);
    show_hex_data_dump(randomBytes, 0);
    std::cout << std::endl << std::endl;

    std::vector<uint8_t> boot_sector_data(n);
    covert_char_vec_to_uint8_vec(randomBytes, boot_sector_data);
    FAT *fat = new FAT(boot_sector_data);
    fat->show_volume_info();


/*
    Disk* disk = new Disk(randomBytes);
    std::cout << std::endl << "Partition List: " << std::endl;
    disk->show_partition_info();

    Partition *partition_1 = disk->get_partition_entry(1);
    NTFS* ntfs = new NTFS(file, partition_1->get_pos_begin_LBA());
    std::cout << std::hex << ntfs->get_total_sectors() << std::endl;
    ntfs->show_volume_info();
    std::cout << std::endl << std::endl;

    std::vector<char> MFT(512*ntfs->get_sectors_per_cluster());
    for (int i=0;i<246;++i){
        dump_random_data(file, MFT,ntfs->get_pos_begin_LBA() + ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster() + ntfs->get_sectors_per_cluster()*i, 512*ntfs->get_sectors_per_cluster());
        std::cout << std::endl << std::endl << "MFT - Hex data - cluster " << std::dec << i << ": " << std::endl;
        show_hex_data_dump(MFT, ntfs->get_pos_begin_LBA() + ntfs->get_logical_cluster_number_MFT()*ntfs->get_sectors_per_cluster()+ ntfs->get_sectors_per_cluster()*i);
    }
*/

    std::cout << std::endl;
    file.close();

    return 0;
}