#include <cstring>
#include <iostream>
using namespace std;
string s[9];
bool row[9][9], col[9][9], st[3][3][9];
bool dfs(int x, int y)
{
    if (y == 9)
        x++, y = 0;
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << s[i] << endl;
        }
        return true;
    }
    if (s[x][y] != '0')
        return dfs(x, y + 1);
    for (int i = 0; i < 9; i++)
    {
        if (!row[x][i] && !col[y][i] && !st[x / 3][y / 3][i])
        {
            s[x][y] = i + '1';
            row[x][i] = col[y][i] = st[x / 3][y / 3][i] = true;
            if (dfs(x, y + 1))
                return true;
            s[x][y] = '0';
            row[x][i] = col[y][i] = st[x / 3][y / 3][i] = false;
        }
    }
    return false;
}
int main()
{
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(st, false, sizeof(st));
    for (int i = 0; i < 9; i++)
    {
        cin >> s[i];
        for (int j = 0; j < 9; j++)
        {
            if (s[i][j] != '0')
            {
                row[i][s[i][j] - '1'] = true;
                col[j][s[i][j] - '1'] = true;
                st[i / 3][j / 3][s[i][j] - '1'] = true;
            }
        }
    }
    dfs(0, 0);
    return 0;
}