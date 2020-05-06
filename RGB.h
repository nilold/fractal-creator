#ifndef FRACTAL_CREATOR_RGB_H
#define FRACTAL_CREATOR_RGB_H

#include <ostream>

struct RGB {
    RGB(double r, double g, double b);
    double r, g, b;
};

RGB operator-(const RGB &first, const RGB &second);


#endif //FRACTAL_CREATOR_RGB_H
