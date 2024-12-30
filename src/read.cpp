#include "read.h"


void pngh::read_ppm(std::string& path) {
    std::streampos size;
    char *buff;

    std::ifstream file;
    file.open(path, std::ios::binary);

    //get the size of the file
    file.seekg(0, std::ios::end);
    size = file.tellg();
    file.seekg(0, std::ios::beg);

    //load data into
    buff = new char[size];
    file.read(buff, size);
    file.close();



    delete[] buff;
    return;
}
