#ifndef FRACTAL_CREATOR_ZOOMLIST_H
#define FRACTAL_CREATOR_ZOOMLIST_H

#include <vector>
#include <utility>

#include "Zoom.h"

class ZoomList {
private:
    double m_xCenter{0}, m_yCenter{0}, m_scale{1.0};
    int m_width{0}, m_height{0};
    std::vector<Zoom> zooms;
public:
    ZoomList(int mWidth, int mHeight);
    void add(const Zoom &zoom);
    std::pair<double, double>do_zoom(int x, int y) const;
};


#endif //FRACTAL_CREATOR_ZOOMLIST_H
