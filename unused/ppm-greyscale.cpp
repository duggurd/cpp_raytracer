#include <iostream>

int main() {
    int height = 200;
    int width = 200;

    std::cout << "P3\n" << width << " " << height <<"\n255\n";
    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {

            auto bw = double(i) / (width-1);
            int bwr = static_cast<int>(255.999 * bw);
            std::cout << bwr << " " << bwr << " " << bwr << "\n";
        }
    }
}