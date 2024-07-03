#include <iostream>

int main() {
    int p, e, i, d, caseNum = 1;

    while (std::cin >> p >> e >> i >> d && p != -1 && e != -1 && i != -1 && d != -1) {
        int k;
        for (k = d + 1; (k - p) % 23 != 0 || (k - e) % 28 != 0 || (k - i) % 33 != 0; k++);
        int days = k - d;
        std::cout << "Case " << caseNum << ": the next triple peak occurs in " << days << " days." << std::endl;
        caseNum++;
    }

    return 0;
}
