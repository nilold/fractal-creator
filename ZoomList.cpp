#include "ZoomList.h"


ZoomList::ZoomList(int width, int height) :
        m_width(width), m_height(height) {}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width / 2.0) * m_scale;
    m_yCenter += -(zoom.y - m_height / 2.0) * m_scale;

    m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::do_zoom(int x, int y) const {

    double xFractal = (x - m_width / 2.0) * m_scale + m_xCenter;
    double yFractal = (y - m_height / 2.0) * m_scale + m_yCenter;

    return {xFractal, yFractal};
}
