#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <array>

namespace pngh {

struct RGBAPixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    RGBAPixel();
    RGBAPixel(unsigned char r, unsigned char g,
              unsigned char b, unsigned char a);
};

struct RGBPixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    RGBPixel();
    RGBPixel(unsigned char r, unsigned char g, unsigned char b);
};

template <typename PixelType>
class ReferenceImage {
private:
    std::array<PixelType> data;
    int width;
    int height;

public:
    ReferenceImage(int width, int height, std::array<PixelType> data);

};

}

#endif // IMAGEDATA_H
