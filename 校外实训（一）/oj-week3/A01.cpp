#include <iostream>
using namespace std;
char Block[27][27];
int n, m;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dfs(int x, int y)
{
    int res = 1;
    Block[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && Block[nx][ny] == '.')
            res += dfs(nx, ny);
    }
    return res;
}
int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        int startx, starty;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> Block[i][j];
                if (Block[i][j] == '@')
                {
                    startx = i;
                    starty = j;
                }
            }
        cout << dfs(startx, starty) << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                Block[i][j] = 0;
    }
    return 0;
}