#include <iostream>

#include "FractalCreator.h"
#include "Zoom.h"
#include "RGB.h"

int main() {
    std::cout << "Started." << std::endl;

    int const WIDTH = 800;
    int const HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.add_zoom(Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.add_zoom(Zoom(312, HEIGHT - 304, 0.1));

    fractalCreator.run();

    std::cout << "Finished." << std::endl;
    return 0;
}
