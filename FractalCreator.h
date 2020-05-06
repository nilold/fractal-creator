#ifndef FRACTAL_CREATOR_FRACTALCREATOR_H
#define FRACTAL_CREATOR_FRACTALCREATOR_H

#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"

class FractalCreator {
    int const m_width = 1024;
    int const m_height = 1024;
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};

    void calculate_iterations();

    void calculate_total_iterations();

    void draw_fractal();

    void write_bitmap(std::string name);

public:
    FractalCreator(int width, int height);

    void add_zoom(const Zoom &zoom);

    void run();


};


#endif //FRACTAL_CREATOR_FRACTALCREATOR_H
