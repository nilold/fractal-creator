#include <iostream>
#include <memory>

#include "Bitmap.h"
#include "Mandelbrot.h"

int main() {
    int const WIDTH = 1024;
    int const HEIGHT = 1024;

    std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

    Bitmap bitmap(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {

            double xFractal = (x - WIDTH / 2 - 220) * 2.0 / WIDTH; // map to -1-1
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            if (iterations != Mandelbrot::MAX_ITERATIONS)
                histogram[iterations]++;

            uint8_t color = (uint8_t) (256 * (double) iterations / Mandelbrot::MAX_ITERATIONS);

            color = color * color * color;

            bitmap.setPixel(x, y, 0, color, 0);

        }
    }

    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
        std::cout << histogram[i] << " " << std::flush;
    }


    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
