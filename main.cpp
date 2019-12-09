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


    Disk* disk = new Disk(randomBytes);
    std::cout << std::endl << "Partition List: " << std::endl;
    disk->show_partition_info();

    Partition *partition_1 = disk->get_partition_entry(0);
    NTFS* ntfs = new NTFS(file, partition_1->get_pos_begin_LBA());
    std::cout << std::hex << ntfs->get_total_sectors() << std::endl;
    ntfs->show_volume_info();
    std::cout << std::endl << std::endl;

    

    std::cout << std::endl;
    file.close();

    return 0;
}