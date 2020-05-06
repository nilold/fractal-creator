#ifndef FRACTAL_CREATOR_MANDELBROT_H
#define FRACTAL_CREATOR_MANDELBROT_H


class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 2000;

    static int getIterations(double x, double y);
};


#endif //FRACTAL_CREATOR_MANDELBROT_H
