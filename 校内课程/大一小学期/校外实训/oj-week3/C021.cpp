#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
const int N = 100010;
int n, m;
int d[N], q[N];
int h[N], e[N], ne[N], idx;
bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
                q[++tt] = j;
        }
    }
    return d[n] == 0;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        d[b]++;
    }
    if (topsort())
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    else
        cout << -1;
    return 0;
}