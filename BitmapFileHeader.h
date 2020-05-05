#ifndef FRACTAL_CREATOR_BITMAPFILEHEADER_H
#define FRACTAL_CREATOR_BITMAPFILEHEADER_H

#include <cstdint>

#pragma pack(push, 2) // will align everything in two bytes, without extra "spaces" between them

namespace nilolib {

    struct BitmapFileHeader {
        char header[2]{'B', 'M'};
        std::int32_t fileSize; // must be 4 bytes, but the platform can have other sizes
        std::int32_t reserved{0};
        std::int32_t dataOffset;
    };

}

#pragma pack(pop)

#endif //FRACTAL_CREATOR_BITMAPFILEHEADER_H
