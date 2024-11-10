#include <iostream>
#include <cstring>
using namespace std;
const int N = 70;
int fate[N][N] = { 0 };
int dx[3] = { -1,0,1 }, dy[3] = { 0,1,0 };
long long dfs(int x, int y, int n)
{
    if (n == 0)
        return 1;
    long long ans = 0;
    fate[x][y] = 1;
    for (int i = 0; i < 3; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < N && yy >= 0 && yy < N && fate[xx][yy] == 0)
            ans += dfs(xx, yy, n - 1);
    }
    fate[x][y] = 0;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << dfs(N / 2, N / 2, n) << endl;
    return 0;
}