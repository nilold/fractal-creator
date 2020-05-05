#include <fstream>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace nilolib;

Bitmap::Bitmap(int width, int height) :
        m_width(width),
        m_height(height),
        m_pPixels(new std::uint8_t[width * height * 3]{/*this initializes everything to zero*/}) {

}

Bitmap::~Bitmap() {}

bool Bitmap::write(std::string filename) {
    BitmapFileHeader bmFileHeader;

    int headerSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    int dataSize = m_width * m_height * 3;

    bmFileHeader.fileSize = headerSize + dataSize;
    bmFileHeader.dataOffset = headerSize;

    BitmapInfoHeader bmInfoHeader;
    bmInfoHeader.width = m_width;
    bmInfoHeader.height = m_height;

    std::ofstream file;

    file.open(filename, std::ios::binary);

    if (!file)
        return false;

    file.write((char *) &bmFileHeader, sizeof(bmFileHeader));
    file.write((char *) &bmInfoHeader, sizeof(bmInfoHeader));
    file.write((char *) m_pPixels.get(), dataSize);


    file.close();
    return !!file;
}

void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {

}