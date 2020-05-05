#include <iostream>
#include <memory>
#include <math.h>

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

            fractal[y * WIDTH + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS)
                histogram[iterations]++;
        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;


            int iterations = fractal[y * WIDTH + x];

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0;

                for (int i = 0; i <= iterations; i++) {
                    hue += ((double) histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }


    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
