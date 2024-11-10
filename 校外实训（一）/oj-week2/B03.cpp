#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
bool st[26][26];
vector<pair<char, int>> path;
int p, q;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };
bool dfs(int x, int y, int cnt)
{
    path.push_back(make_pair(char('A' + x), 1 + y));
    if (cnt == p * q)
    {
        for (auto a : path)
        {
            cout << a.first << a.second;
        }
        cout << endl;
        return true;
    }
    st[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= q || yy < 0 || yy >= p)
            continue;
        if (st[xx][yy])
            continue;
        if (dfs(xx, yy, cnt + 1))
            return true;
    }
    st[x][y] = false;
    path.pop_back();
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        path.clear();
        bool flag = false;
        memset(st, false, sizeof(st));
        cin >> p >> q;
        cout << "#" << i << ":" << endl;
        for (int j = 0; j < q; j++)
        {
            for (int k = 0; k < p; k++)
            {
                if (dfs(j, k, 1))
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "none" << endl;
    }
    return 0;
}