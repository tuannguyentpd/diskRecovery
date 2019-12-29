#include"Helper.h"

#include"Disk.h"
#include"Volume_NTFS.h"
#include"Volume_FAT.h"



int main()
{
    int n = 512;

    // std::ifstream file("diskImages/fat_12_16.img", std::ios::binary|std::ios::in);
    // if (!file) {
    //     std::cerr << "diskImages/fat_12_16.img. Exiting..." << '\n';
    //     return 1;
    // }

    std::ifstream file("/dev/sdb3", std::ios::binary|std::ios::in);
    if (!file) {
        std::cerr << "diskImages/fat_12_16.img. Exiting..." << '\n';
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
    std::cout << std::endl << std::endl;

    std::vector<char> RDET_hex_data(fat->get_RDET_size()*512);
    dump_random_data(file, RDET_hex_data, fat->get_begin_sector_RDET(), fat->get_RDET_size()*512);
    show_hex_data_dump(RDET_hex_data, fat->get_begin_sector_RDET());
    std::cout << std::endl << std::endl;

/*
    file.seekg(4243*2*512);
    std::ofstream f("LearningVocabEnglish.pdf", std::ios::binary|std::ios::out);
    char hexbyte;
    for (int i=0;i<4338849;++i){
        file.read(&hexbyte, 1);
        f.write(&hexbyte, 1);
    }
    f.close();
*/

    std::cout << std::endl;
    file.close();

    return 0;
}