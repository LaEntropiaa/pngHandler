#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <cstring>

namespace pngh {

class ReferenceImage {
public:
    enum class Type {
        RGB,
        RGBA
    };

    enum class Format {
        PPM
    };

    ReferenceImage();
    ReferenceImage(int length, int width, std::vector<unsigned char> data);
    void read(const std::string& file_path, Format format);

private:
    int length;
    int width;
    Type type;
    std::vector<unsigned char> data;

    void read_ppm(const std::string& file_path);


};

}

#endif // IMAGEDATA_H
