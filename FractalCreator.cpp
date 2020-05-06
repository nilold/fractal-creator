#include "FractalCreator.h"
#include "Mandelbrot.h"
#include "RGB.h"

#include<cassert>
#include <cmath>
#include <utility>
#include <vector>

FractalCreator::FractalCreator(int width, int height)
        : m_width(width), m_height(height),
          m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
          m_fractal(new int[width * height]{0}),
          m_bitmap(width, height),
          m_zoomList(ZoomList(width, height)) {
    m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

void FractalCreator::calculate_iterations() {

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            std::pair<double, double> coords = m_zoomList.do_zoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first,
                                                       coords.second);

            m_fractal[y * m_width + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                m_histogram[iterations]++;
            }

        }
    }

}

int FractalCreator::get_range(int iterations) const {
    int range = 0;

    for (int i = 1; i < m_ranges.size(); ++i) {
        range = i;

        if (m_ranges[i] > iterations) break;
    }

    range--;

    assert(range > -1);
    assert(range < m_ranges.size());

    return range;
}

void FractalCreator::draw_fractal() {

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {


            int iterations = m_fractal[y * m_width + x];

            int range = get_range(iterations);
            int rangeTotal = m_totals[range];
            int rangeStart = m_ranges[range];

            RGB &startColor = m_colors[range];
            RGB &endColor = m_colors[range + 1];
            RGB colorDiff = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {

                int totalPixels = 0;

                for (int i = rangeStart; i <= iterations; i++) {
                    totalPixels += m_histogram[i];
                }
                red = startColor.r + colorDiff.r * (double) totalPixels / rangeTotal;
                green = startColor.g + colorDiff.g * (double) totalPixels / rangeTotal;
                blue = startColor.b + colorDiff.b * (double) totalPixels / rangeTotal;

            }

            m_bitmap.setPixel(x, y, red, green, blue);

        }
    }
}

void FractalCreator::add_zoom(const Zoom &zoom) {
    m_zoomList.add(zoom);
}

void FractalCreator::write_bitmap(std::string name) {
    m_bitmap.write(std::move(name));
}

void FractalCreator::calculate_range_totals() {
    int rangeIndex = 0;

    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];
        if (i >= m_ranges[rangeIndex + 1]) {
            ++rangeIndex;
        }
        m_totals[rangeIndex] += pixels;
    }
}

void FractalCreator::calculate_total_iterations() {
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_total += m_histogram[i];
    }
}

void FractalCreator::add_range(double rangeEnd, const RGB &rgb) {
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if (m_bGotFirstRange) {
        m_totals.push_back(0);
    }

    m_bGotFirstRange = true;
}

void FractalCreator::run() {
    calculate_iterations();
    calculate_total_iterations();
    calculate_range_totals();
    draw_fractal();
    write_bitmap("test.bmp");
}
