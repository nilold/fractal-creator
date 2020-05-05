#ifndef FRACTAL_CREATOR_BITMAP_H
#define FRACTAL_CREATOR_BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    std::unique_ptr<std::uint8_t[]> m_pPixels{nullptr};

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
    bool write(std::string filename);
    virtual ~Bitmap();
};

#endif //FRACTAL_CREATOR_BITMAP_H
