cmake_minimum_required(VERSION 3.16)
project(fractal_creator)

set(CMAKE_CXX_STANDARD 14)

add_executable(fractal_creator main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h Zoom.cpp Zoom.h ZoomList.cpp ZoomList.h FractalCreator.cpp FractalCreator.h RGB.cpp RGB.h)