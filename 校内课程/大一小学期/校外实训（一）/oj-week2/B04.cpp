#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define _For(a,b,c) for(int a=b;a<=c;a++)
#define _RFor_(a,b,c) for(int a=b;a>=c;a--)
const int Inf = 0x3f3f3f3f, Inf2 = 0x7fffffff;
int W, H, M;
int minMax[27][27][407];
int dfs(int w, int h, int m)
{
    if (w * h < m + 1)
        return Inf;
    if (m == 0)
        return w * h;
    if (minMax[w][h][m] != -1)
        return minMax[w][h][m];
    if (minMax[w][h][m] != -1)
        return minMax[w][h][m];
    int ans = Inf;
    _For(i, 1, w - 1)
        _For(k, 0, m - 1)
    {
        int m1 = dfs(i, h, k);
        int m2 = dfs(w - i, h, m - k - 1);
        ans = min(ans, max(m1, m2));
    }
    _For(i, 1, h - 1)
        _For(k, 0, m - 1)
    {
        int m1 = dfs(w, i, k);
        int m2 = dfs(w, h - i, m - k - 1);
        ans = min(ans, max(m1, m2));
    }
    return minMax[w][h][m] = ans;
}
int main()
{
    while (true)
    {
        cin >> W >> H >> M;
        if (W == 0 && H == 0 && M == 0)
            break;
        memset(minMax, -1, sizeof(minMax));
        cout << dfs(W, H, M - 1) << endl;
    }
    return 0;
}