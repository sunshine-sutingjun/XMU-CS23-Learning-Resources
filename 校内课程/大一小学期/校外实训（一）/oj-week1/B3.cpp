#include <iostream>

void printPath(int path[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << path[i] << " ";
    std::cout << std::endl;
}

void perm(int n, int path[], int index, bool used[]) {
    if (index == n) {
        printPath(path, n);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            path[index] = i;
            used[i] = true;
            perm(n, path, index + 1, used);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int path[n];
    bool used[n + 1];
    for (int i = 0; i <= n; i++)
        used[i] = false;
    perm(n, path, 0, used);
    return 0;
}