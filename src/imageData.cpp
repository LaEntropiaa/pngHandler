#include "imageData.h"

namespace pngh {

ReferenceImage::ReferenceImage(){}


ReferenceImage::ReferenceImage(int length, int width, std::vector<unsigned char> data) :
    length(length), width(width), data(data) {

    if (length * width * 4 == data.size()) {
        this->type = ReferenceImage::Type::RGBA;
    } else if (length * width * 3 == data.size()) {
        this->type = ReferenceImage::Type::RGB;
    } else {
        throw std::runtime_error("Data size is inconsistent with image dimensions.");
    }
}


void ReferenceImage::read(const std::string &file_path, Format format) {
    if (format == ReferenceImage::Format::PPM) {
        read_ppm(file_path);
    } else {
        throw std::runtime_error("Format is not supported!.");
    }
}


void ReferenceImage::read_ppm(const std::string& file_path) {
    std::streampos size;
    unsigned char *buff;
    const unsigned char ppm_signature[3] = "P6";

    std::ifstream file(file_path, std::ios::binary);

    if (!file) {
        std::runtime_error("PPM file could not be open.");
        return;
    }
    //get the size of the file
    file.seekg(0, std::ios::end);
    size = file.tellg();
    file.seekg(0, std::ios::beg);

    //load data into buffer
    buff = new unsigned char[size];
    file.read(reinterpret_cast<char*>(buff), size);
    file.close();

    //All this is the reading, now the parsing the info into data

    for (int i = 0; i < 2; i++) {
        if (ppm_signature[i] != buff[i]) {
            std::runtime_error("File signature doensn't correspond to a PPM file.");
            delete[] buff;
            return;
        }
    }

    std::string length_string = "";
    std::string width_string = "";
    //Get first length number
    int count = 3;
    while (buff[count] != ' ') {
        length_string += buff[count];
        count++;
    }
    count++;//skip the space between first and second width number
    while (buff[count] != '\n') {
        width_string += buff[count];
        count++;
    }

    //Assignment of values
    this->length = std::stoi(length_string);
    this->width = std::stoi(width_string);
    this->data = std::vector<unsigned char>(buff + (count + 1), buff + size);

    if (length * width * 4 == data.size()) {
        this->type = ReferenceImage::Type::RGBA;
    } else if (length * width * 3 == data.size()) {
        this->type = ReferenceImage::Type::RGB;
    } else {
        throw std::runtime_error("Data size is inconsistent with image dimensions.");
    }

    delete[] buff;
    return;
}



}
