#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    bitset<32> lock;
    int mintimes = 1 << 30;
    cin >> line;
    bitset<32> sourcelock(line);
    cin >> line;
    bitset<32> targetlock(line);
    int n = line.size();
    for (int p = 0; p < 2; p++)
    {
        lock = sourcelock;
        int times = 0;
        int nextButton = p;
        for (int i = 0; i < n; i++)
        {
            if (nextButton == 1)
            {
                times++;
                if (i > 0)
                    lock.flip(i - 1);
                lock.flip(i);
                if (i < n - 1)
                    lock.flip(i + 1);
            }
            if (lock[i] != targetlock[i])
                nextButton = 1;
            else
                nextButton = 0;
        }
        if (lock == targetlock)
            mintimes = min(mintimes, times);
    }
    if (mintimes == 1 << 30)
        cout << "impossible" << endl;
    else
        cout << mintimes << endl;
    return 0;
}