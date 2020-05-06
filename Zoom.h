#ifndef FRACTAL_CREATOR_ZOOM_H
#define FRACTAL_CREATOR_ZOOM_H


struct Zoom {
    int x{0}, y{0};
    double scale{0.0};

    Zoom(int x, int y, double scale);

};

#endif //FRACTAL_CREATOR_ZOOM_H
