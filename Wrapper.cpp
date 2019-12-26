#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include <boost/python.hpp>
#include <python3.6/Python.h>


#include"Helper.h"
#include"Disk.h"
#include"Partition.h"
#include"Volume_NTFS.h"
#include"Volume_FAT.h"
#include"RDET_FAT.h"



BOOST_PYTHON_MODULE(Wrapper) {
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

    class_<Disk>("Disk")
        .def(init<>())
        .def(init<const std::vector<char> &>())
        .def("get_partition_entry", &Disk::show_partition_info, "This is the docstring for Disk::show_partition_info")
        .def("show_partition_info", &Disk::show_partition_info, "This is the docstring for Disk::show_partition_info")
    ;

    class_<Partition>("Partition")
        .def(init<>())
        .def(init<const Partition &>())
        .def(init<const std::vector<uint8_t> &>())
        .def("is_active", &Partition::is_active, "This is the docstring for Partition::is_active")
        .def("get_head_begin", &Partition::get_head_begin, "This is the docstring for Partition::get_head_begin")
        .def("get_sector_begin", &Partition::get_sector_begin, "This is the docstring for Partition::get_sector_begin")
        .def("get_cylinder_begin", &Partition::get_cylinder_begin, "This is the docstring for Partition::get_cylinder_begin")
        .def("get_type_fs", &Partition::get_type_fs, "This is the docstring for Partition::get_type_fs")
        .def("get_head_end", &Partition::get_head_end, "This is the docstring for Partition::get_head_end")
        .def("get_sector_end", &Partition::get_sector_end, "This is the docstring for Partition::get_sector_end")
        .def("get_cylinder_end", &Partition::get_cylinder_end, "This is the docstring for Partition::get_cylinder_end")
        .def("get_pos_begin_LBA", &Partition::get_pos_begin_LBA, "This is the docstring for Partition::get_pos_begin_LBA")
        .def("get_num_sector_total", &Partition::get_num_sector_total, "This is the docstring for Partition::get_num_sector_total")
        .def("get_finish_sign", &Partition::get_finish_sign, "This is the docstring for Partition::get_finish_sign")
        .def("get_active", &Partition::get_active, "This is the docstring for Partition::get_active")
        .def("is_finish", &Partition::is_finish, "This is the docstring for Partition::is_finish")
    ;

    class_<NTFS>("NTFS", init<>())
        .def(init<const NTFS &>())
        .def(init<const std::vector<uint8_t> &>())
        .def(init<std::ifstream &, const uint32_t &>())
        .def("get_OEMID", &NTFS::get_OEMID, "This is the docstring for NTFS::get_OEMID")
        .def("get_pos_begin_LBA", &NTFS::get_pos_begin_LBA, "This is the docstring for NTFS::get_pos_begin_LBA")
        .def("get_bytes_per_sector", &NTFS::get_bytes_per_sector, "This is the docstring for NTFS::get_bytes_per_sector")
        .def("get_sectors_per_cluster", &NTFS::get_sectors_per_cluster, "This is the docstring for NTFS::get_sectors_per_cluster")
        .def("get_reserved_sector", &NTFS::get_reserved_sector, "This is the docstring for NTFS::get_reserved_sector")
        .def("get_media_descripter", &NTFS::get_media_descripter, "This is the docstring for NTFS::get_media_descripter")
        .def("get_sectors_per_track", &NTFS::get_sectors_per_track, "This is the docstring for NTFS::get_sectors_per_track")
        .def("get_number_of_heads", &NTFS::get_number_of_heads, "This is the docstring for NTFS::get_number_of_heads")
        .def("get_hidden_sectors", &NTFS::get_hidden_sectors, "This is the docstring for NTFS::get_hidden_sectors")
        .def("get_total_sectors", &NTFS::get_total_sectors, "This is the docstring for NTFS::get_total_sectors")
        .def("get_logical_cluster_number_MFT", &NTFS::get_logical_cluster_number_MFT, "This is the docstring for NTFS::get_logical_cluster_number_MFT")
        .def("get_logical_cluster_number_MFTMirr", &NTFS::get_logical_cluster_number_MFTMirr, "This is the docstring for NTFS::get_logical_cluster_number_MFTMirr")
        .def("get_clusters_per_file_record_segment", &NTFS::get_clusters_per_file_record_segment, "This is the docstring for NTFS::get_clusters_per_file_record_segment")
        .def("get_cluster_per_index_buffer", &NTFS::get_cluster_per_index_buffer, "This is the docstring for NTFS::get_cluster_per_index_buffer")
        .def("get_volume_serial_number", &NTFS::get_volume_serial_number, "This is the docstring for NTFS::get_volume_serial_number")
        .def("get_end_sector_marker", &NTFS::get_end_sector_marker, "This is the docstring for NTFS::get_end_sector_marker")
        .def("show_volume_info", &NTFS::get_OEMID, "This is the docstring for NTFS::show_volume_info")
        .def("set_attrs_from_boot_sector", &NTFS::set_attrs_from_boot_sector, "This is the docstring for NTFS::set_attrs_from_boot_sector")
    ;

    class_<FAT>("FAT", init<>())
        .def(init<const FAT &>())
        .def(init<const std::vector<uint8_t> &>())
        .def(init<std::ifstream &, const uint32_t &>())
        .def("get_OEMID", &FAT::get_OEMID, "This is the docstring for FAT::get_OEMID")
        .def("get_pos_begin_LBA", &FAT::get_pos_begin_LBA, "This is the docstring for FAT::get_pos_begin_LBA")
        .def("gget_bytes_per_sector", &FAT::get_bytes_per_sector, "This is the docstring for FAT::get_bytes_per_sector")
        .def("get_sectors_per_cluster", &FAT::get_sectors_per_cluster, "This is the docstring for FAT::get_sectors_per_cluster")
        .def("get_sectors_before_FAT_table", &FAT::get_sectors_before_FAT_table, "This is the docstring for FAT::get_sectors_before_FAT_table")
        .def("get_num_FAT_table", &FAT::get_num_FAT_table, "This is the docstring for FAT::get_num_FAT_table")
        .def("get_entries_of_RDET", &FAT::get_entries_of_RDET, "This is the docstring for FAT::get_entries_of_RDET")
        .def("get_sectors_of_volume", &FAT::get_sectors_of_volume, "This is the docstring for FAT::get_sectors_of_volume")
        .def("get_volume_signature", &FAT::get_volume_signature, "This is the docstring for FAT::get_volume_signature")
        .def("get_sectors_of_FAT", &FAT::get_sectors_of_FAT, "This is the docstring for FAT::get_sectors_of_FAT")
        .def("get_sectors_per_track", &FAT::get_sectors_per_track, "This is the docstring for FAT::get_sectors_per_track")
        .def("get_number_of_heads", &FAT::get_number_of_heads, "This is the docstring for FAT::get_number_of_heads")
        .def("get_distance_vol_describe_to_vol_begin", &FAT::get_distance_vol_describe_to_vol_begin, "This is the docstring for FAT::get_distance_vol_describe_to_vol_begin")
        .def("get_volume_size", &FAT::get_volume_size, "This is the docstring for FAT::get_volume_size")
        .def("get_disk_physical_signature", &FAT::get_disk_physical_signature, "This is the docstring for FAT::get_disk_physical_signature")
        .def("get_OS_signature", &FAT::get_OS_signature, "This is the docstring for FAT::get_OS_signature")
        .def("get_volume_serial_number", &FAT::get_volume_serial_number, "This is the docstring for FAT::get_volume_serial_number")
        .def("get_volume_label", &FAT::get_volume_label, "This is the docstring for FAT::get_volume_label")
        .def("get_FAT_type", &FAT::get_FAT_type, "This is the docstring for FAT::get_FAT_type")
        .def("get_end_sector_marker", &FAT::get_end_sector_marker, "This is the docstring for FAT::get_end_sector_marker")
        .def("get_RDET_size", &FAT::get_RDET_size, "This is the docstring for FAT::get_RDET_size")
        .def("get_begin_sector_RDET", &FAT::get_begin_sector_RDET, "This is the docstring for FAT::get_begin_sector_RDET")
        .def("get_begin_sector_FAT_table", &FAT::get_begin_sector_FAT_table, "This is the docstring for FAT::get_begin_sector_FAT_table")
        .def("get_begin_sector_data_area", &FAT::get_begin_sector_data_area, "This is the docstring for FAT::get_begin_sector_data_area")
        .def("show_volume_info", &FAT::show_volume_info, "This is the docstring for FAT::show_volume_info")
        .def("set_attrs_from_boot_sector", &FAT::set_attrs_from_boot_sector, "This is the docstring for FAT::set_attrs_from_boot_sector")
    ;

    class_<RDET_FAT>("RDET_FAT", init<>())
        .def(init<const RDET_FAT &>())
        .def(init<const std::vector<uint8_t> &>())
        .def("RDET_FAT", &RDET_FAT::set_full_name, "This is the docstring for RDET_FAT::set_full_name")
    ;
}



#endif // !__WRAPPER_H__