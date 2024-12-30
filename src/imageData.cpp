#include "imageData.h"

struct pngh::RGBAPixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    pngh::RGBAPixel();
    pngh::RGBAPixel(unsigned char r, unsigned char g,
              unsigned char b, unsigned char a) :
              r(r), g(g), b(b), a(a) {}
};

struct pngh::RGBPixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    pngh::RGBPixel();
    pngh::RGBPixel(unsigned char r, unsigned char g, unsigned char b) :
        r(r), g(g), b(b) {}
};

template <typename PixelType>
class pngh::ReferenceImage {
private:
    int height;
    int width;
    std::array data;

public:

    pngh::ReferenceImage(int width, int height, std::array<PixelType> data) :
        width(width), height(height), data(data) {}

};

