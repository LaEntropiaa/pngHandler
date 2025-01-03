#include "pngHandler.h"

int main() {
    pngh::ReferenceImage imagen;
    imagen.read("/home/alonso/Downloads/sample-ppm-files-sample_1280x853.ppm",
                pngh::ReferenceImage::Format::PPM);
}
