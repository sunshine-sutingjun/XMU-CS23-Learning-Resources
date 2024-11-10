#include <iostream>
using namespace std;
#define N 16
int log[1 << N];
inline int lowbit(int n)
{
    return n & -n;
}
int query(int n)
{
    return log[lowbit(n)];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= N; i++)
    {
        log[1 << i] = i;
    }
    cout << query(n);
    return 0;
}