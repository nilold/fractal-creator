#include <iostream>
#include "Bitmap.h"

int main() {
    Bitmap bitmap(800, 600);
    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
