#include <iostream>
using namespace std;

int countWays(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return countWays(n - 1) + countWays(n - 2);
    }
}

int main() {
    int n;
    cin >> n;
    int ways = countWays(n);
    cout << ways << endl;
    return 0;
}