#include <iostream>
#include <string>
#include<bitset>
#include<vector>
#include<iterator>

#include<iomanip>
#include<ctype.h>

#include<map>

using namespace std;

int main()
{
    char block[512];
    int length=0;
    
    uint8_t a='O', b='P';

    uint8_t c = 0xff;
    std::cout << char(c) << std::endl;

    printf("%02hx\n",a); //117='O'
    printf("%02hx\n",b); //120='P'

    std::cout << std::bitset<8>(a) << std::endl;
    std::cout << std::bitset<8>(c) <<std::endl;
    
    uint16_t sum = (a<<8) + b;
    std::cout << std::bitset<8>(c>>2) << std::endl;
    printf("%04hx\n",sum);

    char f1 = 'O', f2='P';
    uint16_t final = (f1<<8)+f2;
    printf("%d\n",final);
    std::cout << (20304==uint16_t((f1<<8)+f2)) << std::endl;

    char test='O'>>1;
    uint8_t test1=test;
    printf("%c\n",test1);

    char _1='A', _2='B', _3='C', _4='D';
    std::cout << std::bitset<8>(_1) << std::endl;
    std::cout << std::bitset<8>(_2) << std::endl;
    std::cout << std::bitset<8>(_3) << std::endl;
    std::cout << std::bitset<8>(_4) << std::endl;
    uint32_t total = uint32_t((((((_1<<8)+_2)<<8)+_3)<<8)+_4);
    std::cout << std::bitset<32>(total) << std::endl;


    std::vector<int> nums;
    //nums = new vector<int>();
    for (int i=1;i<=10;++i){
        nums.push_back(i);
    }

    for (int i=0;i<nums.size();++i){
        std::cout << nums[i] << '\t';
    }
    std::cout<<std::endl;

    uint8_t x = 0x55, y = 0xaa;
    std::cout << std::hex << uint16_t((x<<8)+y) <<std::endl;

    std::map<uint8_t, string> code_map_type_fs;
    code_map_type_fs[0x09] = "AIX data partition";
    //code_map_type_fs.insert(0x09, "AIX data partition");
    std::cout << code_map_type_fs[9].length() <<std::endl;
    std::cout << code_map_type_fs[19].length() <<std::endl;

    std::vector<uint8_t> code{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0f, 0x65, 0x66, 0x81, 0x85, 0x8a, 0x93, 0xa0,0xa3, 0xa8, 0xbe, 0xc3, 0xdb, 0xec, 0xf9, 0xfa, 0xff};
    std::vector<string> type_fs{"DOS 12-bit FAT", "XENIX root", "EXNIX /usr", "DOS 3.0+ 16bit FAT", "Extended Partition", "DOS 3.1+ 16bit FAT", "OS/2 IFS", "OS/2 (v1.0-1.3 only", "AIX data partition", "OS2 Boot Manager", "WIN95 FAT32", "WIN92 FAT32, LBA mapped", "Extended Partition - BIOS", "Novell Netware 386", "Novell Netware SMS", "MINIX", "Linux extended", "Linux kernel", "Hidden Linux native", "Laptop hibernation", "HP volume Expansion", "Mac OS-X", "Solaris 8 boot", "Hidden Linux swap", "CP/M", "SkyOS SkyFS", "pCache", "Bochs", "Xenix Bad Block table"};
    for (int i=0;i< code.size();++i){
        code_map_type_fs[code[i]] = type_fs[i];
    }
    uint8_t t1 = code[5];
    uint8_t t2 = code[10];
    std::cout << std::setw(25) << std::left << code_map_type_fs[t1];
    std::cout << code_map_type_fs[t2] << std::endl;

    char code_char[8] = {0x4e, 0x54,0x46, 0x53, 0x20, 0x20, 0x20, 0x20};
    string res = "";
    for (int i=0;i<8;++i){
        res += char(code_char[i]);
    }

    std::cout << res << std::endl;

    return 0;
}