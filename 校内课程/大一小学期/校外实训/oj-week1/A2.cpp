#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int a = 2; a <= n; a++) {
        for (int b = 2; b <= a; b++) {
            for (int c = b; c <= a; c++) {
                for (int d = c; d <= a; d++) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d) {
                        std::cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}