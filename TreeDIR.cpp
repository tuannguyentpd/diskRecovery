#include "TreeDIR.h"



TreeDIR::TreeDIR(){
    this->helper = new Helper();
    this->numItems = 0;
}
TreeDIR::~TreeDIR(){
    delete this->helper;
}
TreeDIR::TreeDIR(const vector<char> &rDET){
    this->helper = new Helper();
    this->numItems = 0;
}
TreeDIR::TreeDIR(const uint32_t& beginCluster){
    this->helper = new Helper();
    this->numItems = 0;
}
TreeDIR::TreeDIR(const string &name, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_)
    :Component(name, type_, clusterBegin, size_){
        this->helper = new Helper();
}
TreeDIR::TreeDIR(const string &name, const char& type_,const uint32_t& clusterBegin, const uint32_t &size_, const uint32_t &rank_, std::ifstream &f, const uint32_t& idxSector)
    :Component(name, type_, clusterBegin, size_, rank_){
    this->helper = new Helper();

    std::string name_temp = "";
    char type_temp = 0x10;
    uint32_t indexClusterBegin_temp = 0;
    uint32_t size_temp = 0;
    uint32_t rank_temp = 0;
    uint32_t idxSector_temp = idxSector;

    std::vector<char> ext_entries;
    std::vector<char> entry(32);
    this->helper->dump_random_data(f, entry, idxSector_temp, 32);
    int i, j;
    int count = 0;
    while (this->vectorIsEmpty(entry)==false)
    {
        if (entry[11]==0x0f){//Entry phu
            for (i=1;i<32;++i) //offset dau moi entry khong dung vi no dung de chi trang thai (xoa, con,...)
                ext_entries.push_back(entry[i]);
            // std::cout << "Vao: " << ext_entries.size() << std::endl;
        }
        else // Entry chinh
        {
            name_temp = "";
            if (ext_entries.size() == 0){ //Khong co entry phu
                // std::cout << "Khong co entry phu" << std::endl;
                for (i=0;i<6;++i){ // 2byte 6,7 la ~1
                    if (isgraph(entry[i]))
                        name_temp += entry[i];
                }
                if (entry[11]!=0x0f){
                    name_temp += '.';
                    for (i=8;i<11;++i){
                    if (isgraph(entry[i]))
                        name_temp += entry[i];
                }
                }
            }
            else //co entry phu
            {
                // std::cout << "Co entry phu" << std::endl;
                for (i=ext_entries.size()/31-1;i>=0;--i){
                    for (j=0;j<31;++j){
                        if (isgraph(ext_entries[31*i+j]))
                            name_temp += ext_entries[31*i+j];
                    }
                }
                ext_entries.clear();
            }
            type_temp = entry[11];
            rank_temp = rank + 1;
            indexClusterBegin_temp = uint32_t((((((entry[21]<<8)|entry[20])<<8)|entry[27])<<8)|entry[26]);
            size_temp = uint32_t((((((entry[31]<<8)|entry[30])<<8)|entry[29])<<8)|entry[28]);

            if (type_temp == 0x10){
                
            }
            else{
                Component* file = new File(name_temp, type_temp, indexClusterBegin_temp, size_temp, rank_temp);
                this->files.push_back(file);
            }
        }
        f.read(&entry[0], 32);
        
        ++count;
        if (count == 7) // Max 512 -> so entry cua RDET
            return;
    }
    
}
void TreeDIR::show(){
    cout << std::setw(this->rank*3) << "" << "|--" << this->name << endl;
    //cout << std::setw(this->rank*3) << "|-" << std::setw(2) << this->type << std::setw(15) << this->size  << std::setw(15) << this->indexClusterBegin << "   " <<this->name << endl;
    for (int i=0;i<this->files.size();++i){
        this->files[i]->show();
    }
}
void TreeDIR::add(Component* items){
    this->files.push_back(items);
}
bool TreeDIR::vectorIsEmpty(const vector<char>&entry){
    for (int i=0;i<entry.size();++i){
        if (entry[i] != 0x00)
            return false;
    }
    return true;
}
int TreeDIR::getNumItems(){
    return this->files.size();
}