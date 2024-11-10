#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1010;
int n, m;
char a[N][N];
int b[N][N];
int bfs()
{
    memset(b, -1, sizeof(b));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                q.push({ i,j });
                b[i][j] = 0;
            }
        }
    }
    int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && b[x][y] == -1)
            {
                b[x][y] = b[t.first][t.second] + 1;
                q.push({ x,y });
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)    scanf("%s", a[i]);
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", b[i][j]);
        }
        cout << endl;
    }
    return 0;
}