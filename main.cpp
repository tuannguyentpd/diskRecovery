#include"Helper.h"

#include"Disk.h"
#include"Volume_NTFS.h"
#include"Volume_FAT.h"

#include "File.h"
#include"TreeDIR.h"



int main()
{
    int n = 512;

    Helper *helper = new Helper();


    // std::ifstream file("diskImages/fat_12_16.img", std::ios::binary|std::ios::in);
    std::ifstream file("/dev/sdb3", std::ios::binary|std::ios::in);
    if (!file) {
        std::cerr << "diskImages/fat_12_16.img. Exiting..." << '\n';
        return 1;
    }

    std::vector<char> randomBytes(n);
    helper->dump_sector(file, randomBytes, 0);
    //helper->show_hex_data_dump(randomBytes, 0);
    //std::cout << std::endl << std::endl;

    std::vector<uint8_t> boot_sector_data(n);
    helper->covert_char_vec_to_uint8_vec(randomBytes, boot_sector_data);
    FAT *fat = new FAT(boot_sector_data, file);
    
    //fat->recoverFileWithExt(file, "recoverFolder", "cpp");
    // fat->listFile();
    // fat->tree();
    // fat->recoverAllFile(file, "recoverFolder");
    
    char option;
    string ext = "";
    while (true)
    {
        cout << "***************** OPTION *****************" << endl;
        cout << "***************** 1: Recover all *****************" << endl;
        cout << "***************** 2: Recover file: *****************" << endl;
        cout << "***************** 3: Exist: *****************" << endl;
        
        std::cout << "Nhap lua chon: ";
        std::cin >> option;


        switch (option)
        {
        case '1':
            fat->recoverAllFile(file, "recoverFolder");
            break;
        case '2':
            std::cout << "Nhap ten file mo rong: ";
            std::cin >> ext;
            fat->recoverFileWithExt(file, "recoverFolder", ext);
            break;
        case '3':
            exit(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Lua chon khong hop le!" << std::endl;
            break;
        }
    }

    
    std::cout << std::endl;
    file.close();

    delete helper;
    delete fat;

    return 0;
}