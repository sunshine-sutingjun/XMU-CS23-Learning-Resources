#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 160;
char s[N][N];
int nums[N][N] = { 0 };
int m, n;
int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int ans = m * n;
    int dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int xx = p.first + dx[i], yy = p.second + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && s[xx][yy] == '.')
            {
                s[xx][yy] = '*';
                q.push(make_pair(xx, yy));
                nums[xx][yy] = nums[p.first][p.second] + 1;
            }
            if (s[xx][yy] == 'H')
            {
                nums[xx][yy] = nums[p.first][p.second] + 1;
                ans = min(ans, nums[xx][yy]);
            }
        }
    }
    return ans;
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 'K')
            {
                x = i;
                y = j;
            }
        }
    }
    cout << bfs(x, y) << endl;
}