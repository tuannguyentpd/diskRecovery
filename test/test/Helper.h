//g++ -o Helper.so Helper.cpp -std=c++11 -fPIC -shared -Wall -Wextra `python3.6-config --includes --libs` -lboost_python3

#ifndef __HELPER_H__
#define __HELPER_H__

#include <boost/python.hpp>

#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<iomanip>

class Helper{
    private:
        int m_i;
    public:
        Helper(int i);
        Helper();
        ~Helper();
    public:
        void set_code_mapping_type_fs(std::map<uint8_t, std::string> &code_mapping_type_fs, const std::vector<uint8_t> &code, const std::vector<std::string> &type_fs);
        void show_hex_data_dump(const std::vector<char> data,const int &sector_range);
        int dump_sector(std::ifstream &f, std::vector<char> &data,const int &sector_range);
        int dump_random_data(std::ifstream &f, std::vector<char> &data, const int&sector_range, const int&num_bytes);
        long int get_size_of_file(std::ifstream &f);
        bool covert_char_vec_to_uint8_vec(const std::vector<char> &src, std::vector<uint8_t> &des);
        void show_hex_data_sector_uint8(const std::vector<uint8_t> &sector_data);
};


BOOST_PYTHON_MODULE(MyHelper) {
  using namespace boost::python;

  class_<Helper>("Helper", init<>())
      .def("set_code_mapping_type_fs", &Helper::set_code_mapping_type_fs, "This is the docstring for &Helper::set_code_mapping_type_fs")
      .def("show_hex_data_dump", &Helper::show_hex_data_dump, "This is the docstring for &Helper::show_hex_data_dump")
      .def("dump_sector", &Helper::dump_sector, "This is the docstring for &Helper::dump_sector")
      .def("dump_random_data", &Helper::dump_random_data, "This is the docstring for &Helper::dump_random_data")
      .def("get_size_of_file", &Helper::get_size_of_file, "This is the docstring for &Helper::get_size_of_file")
      .def("covert_char_vec_to_uint8_vec", &Helper::covert_char_vec_to_uint8_vec, "This is the docstring for &Helper::covert_char_vec_to_uint8_vec")
      .def("show_hex_data_sector_uint8", &Helper::show_hex_data_sector_uint8, "This is the docstring for &Helper::show_hex_data_sector_uint8")
      ;
}


#endif // !__HELPER_H__