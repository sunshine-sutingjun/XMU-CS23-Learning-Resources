#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 110;
char s[N][N];
int nums[N][N] = { 0 };
int m, n;
int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    s[x][y] = '*';
    int ans = 0;
    int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && s[a][b] == '.')
            {
                q.push(make_pair(a, b));
                s[a][b] = '*';
                nums[a][b] = nums[t.first][t.second] + 1;
                ans = max(ans, nums[a][b]);
            }
        }
    }
    return ans;
}
int main()
{
    int x, y;
    cin >> n >> m >> y >> x;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    cout << bfs(m - x, y - 1) << endl;
    return 0;
}