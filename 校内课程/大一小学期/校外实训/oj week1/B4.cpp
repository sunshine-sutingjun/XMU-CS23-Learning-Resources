#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string line;
    cin >> line;
    sort(line.begin(), line.end());
    do {
        cout << line << endl;
    } while (next_permutation(line.begin(), line.end()));
    return 0;
}