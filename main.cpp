#include <iostream>

#include "FractalCreator.h"
#include "Zoom.h"

int main() {
    std::cout << "Started." << std::endl;

    int const WIDTH = 800;
    int const HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.add_zoom(Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.add_zoom(Zoom(312, HEIGHT - 304, 0.1));

    fractalCreator.calculate_iterations();
    fractalCreator.calculate_total_iterations();
    fractalCreator.draw_fractal();

    fractalCreator.write_bitmap("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
