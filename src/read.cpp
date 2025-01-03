#include "read.h"


void pngh::read_ppm(std::string path) {
    std::streampos size;
    char *buff;
    const char ppm_signature[3] = "P6";

    std::ifstream file;
    file.open(path, std::ios::binary);

    //get the size of the file
    file.seekg(0, std::ios::end);
    size = file.tellg();
    file.seekg(0, std::ios::beg);

    //load data into buffer
    buff = new char[size];
    file.read(buff, size);
    file.close();

    //All this is the reading, now the parsing the info into data

    for (int i = 0; i < 2; i++) {
        if (ppm_signature[i] != buff[i]) {
            std::cerr << "File signature is not a ppm signature.\n";
        }
    }

    std::string length_string = "";
    std::string width_string = "";
    //Get first length number
    int count = 3;
    while (buff[count] != ' ') {
        length_string = length_string + buff[count];
        count++;
    }
    count++;//skip the space between first and second eidth number
    while (buff[count] != '\n') {
        width_string = width_string + buff[count];
        count++;
    }

    int lenght_int = std::stoi(length_string);
    int width_int = std::stoi(width_string);



    delete[] buff;
    return;
}

