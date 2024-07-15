#include <cstring>
#include <iostream>
using namespace std;
int res[92][8];
int path[8];
int cnt = 0;
void dfs(int n)
{
    if (n == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            res[cnt][i] = path[i];
        }
        cnt++;
        return;
    }
    for (int i = 1; i <= 8; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (path[j] == i || abs(path[j] - i) == abs(j - n))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            path[n] = i;
            dfs(n + 1);
        }
    }
}
int main()
{
    int T, n;
    memset(path, 0, sizeof(path));
    cnt = 0;
    dfs(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < 8; i++)
        {
            cout << res[n - 1][i];
        }
        cout << endl;
    }
    return 0;
}