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


    std::ifstream file("diskImages/fat_12_16.img", std::ios::binary|std::ios::in);
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
    FAT *fat = new FAT(boot_sector_data);
    // fat->show_volume_info();
    // std::cout << std::endl << std::endl;


    TreeDIR *treeDir = new TreeDIR(".", 'd', fat->get_begin_sector_RDET(), 0, 0, file, fat->get_begin_sector_RDET());

    std::cout << "Num items : " << treeDir->getNumItems() << std::endl;
    treeDir->show();




    // std::vector<char> RDET_hex_data(fat->get_RDET_size()*fat->get_bytes_per_sector());
    // helper->dump_random_data(file, RDET_hex_data, fat->get_begin_sector_RDET(), fat->get_RDET_size()*fat->get_bytes_per_sector());
    // helper->show_hex_data_dump(RDET_hex_data, fat->get_begin_sector_RDET());
    // std::cout << std::endl << std::endl;

    // helper->dump_random_data(file, RDET_hex_data, fat->get_begin_sector_data_area()+(8481-2)*fat->get_sectors_per_cluster(), fat->get_RDET_size()*fat->get_bytes_per_sector());
    // helper->show_hex_data_dump(RDET_hex_data, fat->get_begin_sector_data_area()+(8481-2)*fat->get_sectors_per_cluster());
    // std::cout << std::endl << std::endl;



    // file.seekg((fat->get_begin_sector_data_area()+(9-2)*2)*fat->get_bytes_per_sector());
    // std::ofstream f("LearningVocabEnglish.pdf", std::ios::binary|std::ios::out);
    // char hexbyte;
    // for (int i=0;i<4338849;++i){
    //     file.read(&hexbyte, 1);
    //     f.write(&hexbyte, 1);
    // }
    // f.close();


    
    std::cout << std::endl;
    file.close();

    delete helper;
    delete fat;

    return 0;
}



/*
int main(){
    TreeDIR *treeDir = new TreeDIR(".", 'd', 0, 300, 0);

    TreeDIR *tree1 = new TreeDIR("Folder1", 'd', 0, 300, 1);
    File *file1 = new File("file1.txt",'f', 100, 100, 2);
    tree1->add(file1);
    File *file2 = new File("file2.txt",'f', 200, 200, 2);
    tree1->add(file2);
    TreeDIR *tree2 = new TreeDIR("Folder1", 'd', 300, 2000, 1);
    File *file3 = new File("file3.txt",'f', 300, 300, 2);
    File *file4 = new File("file4.txt",'f', 400, 400, 2);
    File *file5 = new File("file5.txt",'f', 500, 500, 2);
    File *file6 = new File("file6.txt",'f', 600, 600, 2);
    tree2->add(file3);
    tree2->add(file4);
    tree2->add(file5);
    tree2->add(file6);
    treeDir->add(tree1);
    treeDir->add(tree2);
    TreeDIR *tree3 = new TreeDIR("Folder3", 'd', 3650, 35000, 2);
    File *file7 = new File("file7.txt",'f', 355, 346, 3);
    File *file8 = new File("file8.txt",'f', 400456, 870, 3);
    File *file9 = new File("file9.txt",'f', 50456, 5640, 3);
    tree3->add(file7);
    tree3->add(file8);
    tree3->add(file9);
    tree2->add(tree3);
    
    treeDir->show();

    return 0;
}
*/