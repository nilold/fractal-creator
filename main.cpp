#include <iostream>

#include "FractalCreator.h"
#include "Zoom.h"
#include "RGB.h"

int main() {
    std::cout << "Started." << std::endl;

    int const WIDTH = 800;
    int const HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.add_range(0.0, RGB(0, 0, 0));
    fractalCreator.add_range(0.1, RGB(255, 0, 0));
    fractalCreator.add_range(0.2, RGB(0, 255, 0));
    fractalCreator.add_range(0.3, RGB(0, 0, 255));
//    fractalCreator.add_range(0.6, RGB(255, 255, 255));
    fractalCreator.add_range(1.0, RGB(0, 0, 255));

    fractalCreator.add_zoom(Zoom(300, HEIGHT - 200, 0.05));
//    fractalCreator.add_zoom(Zoom(182, HEIGHT - 308, 0.015));
//    fractalCreator.add_zoom(Zoom(230, HEIGHT - 304, 0.1));

    fractalCreator.run();

    std::cout << "Finished." << std::endl;
    return 0;
}
