#include "FractalCreator.h"
#include "Mandelbrot.h"

#include <cmath>
#include <utility>

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

void FractalCreator::draw_fractal() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = m_fractal[y * m_width + x];

            if (iterations != Mandelbrot::MAX_ITERATIONS) {

                double hue = 0.0;

                for (int i = 0; i <= iterations; i++) {
                    hue += ((double) m_histogram[i]) / m_total;
                }

                red = 0 * hue;
                green = 255 * hue;
                blue = 0 * hue;
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

void FractalCreator::calculate_total_iterations() {
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_total += m_histogram[i];
    }
}

void FractalCreator::run() {
    calculate_iterations();
    calculate_total_iterations();
    draw_fractal();
    write_bitmap("test.bmp");
}
