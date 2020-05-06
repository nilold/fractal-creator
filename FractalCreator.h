#ifndef FRACTAL_CREATOR_FRACTALCREATOR_H
#define FRACTAL_CREATOR_FRACTALCREATOR_H

#include <vector>

#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "RGB.h"

class FractalCreator {
    int const m_width{1024};
    int const m_height{1024};
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};

    std::vector<int> m_ranges;
    std::vector<RGB> m_colors;
    std::vector<int> m_totals;

    bool m_bGotFirstRange{false};

    void calculate_iterations();

    void calculate_total_iterations();

    void calculate_range_totals();

    void draw_fractal();

    void write_bitmap(std::string name);

    int get_range(int iterations) const;

public:
    FractalCreator(int width, int height);

    void add_range(double rangeEnd, const RGB &rgb);

    void add_zoom(const Zoom &zoom);

    void run();


};


#endif //FRACTAL_CREATOR_FRACTALCREATOR_H
