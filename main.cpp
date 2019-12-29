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
    int idx;
    while (true)
    {
        cout << "***************** OPTION *****************" << endl;
        cout << "* 1: Recover all                         *" << endl;
        cout << "* 2: Recover file                        *" << endl;
        cout << "* 3: Dump sector hex data                *" << endl;
        cout << "* 4: Show Volumn's Infomations           *" << endl;
        cout << "* 5: Dump sector RDET hex data           *" << endl;
        cout << "* 6: Dum cluster (data area) - hex data  *" << endl;
        cout << "* 7: Dum FAT table hex data              *" << endl;
        cout << "* 8: Exist                               *" << endl;
        cout << "***************** OPTION *****************" << endl;
        
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
            std::cout << "Nhap so thu tu sector: ";
            std::cin >> idx;
            fat->dumSectorHexData(file, idx);
            break;
        case '4':
            fat->show_volume_info();
            break;
        case '5':
            fat->dumpRDETHexData(file);
            break;
        case '6':
            std::cout << "Nhap so thu tu cluster trong vung data: ";
            std::cin >> idx;
            fat->dumpClusterDataArea(file, idx);
            break;
        case '7':
            fat->showFATTableHexData(file);
            break;
        case '8':
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