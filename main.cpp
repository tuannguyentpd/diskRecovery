#include"Helper.h"

#include"Disk.h"



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
    show_hex_data_dump(randomBytes, 0);
    std::cout << std::endl; 
    std::cout << std::endl;
    std::cout << std::endl;


    Disk* disk = new Disk(randomBytes);
    disk->show_partition_info();


    file.close();

    return 0;
}