#ifndef __HELPER_H__
#define __HELPER_H__

#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<iomanip>

void set_code_mapping_type_fs(std::map<uint8_t, std::string> &, const std::vector<uint8_t> &, const std::vector<std::string> &);
void show_hex_data_dump(const std::vector<char>, const int);
long int get_size_of_file(std::ifstream &);
int dump_sector(std::ifstream &, std::vector<char> &, const int);


#endif // !__HELPER_H__