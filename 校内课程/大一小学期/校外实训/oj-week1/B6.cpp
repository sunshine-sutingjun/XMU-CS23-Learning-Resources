#include <cstring>
#include <iostream>
using namespace std;

int res[92][8]; // 存储所有可能的解决方案
int path[8];    // 当前解的路径
int cnt = 0;    // 计数器，记录找到的解的数量

void dfs(int n)
{
    if (n == 8)
    {
        // 当找到一个解时，保存到res数组中
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
        // 检查当前位置是否可以放置皇后
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
            path[n] = i; // 放置皇后
            dfs(n + 1);  // 递归到下一行
        }
    }
}

int main()
{
    int T, n;
    memset(path, 0, sizeof(path));
    cnt = 0;
    dfs(0); // 预先计算所有可能的解决方案
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < 8; i++)
        {
            cout << res[n - 1][i]; // 输出第n个解
        }
        cout << endl;
    }
    return 0;
}
