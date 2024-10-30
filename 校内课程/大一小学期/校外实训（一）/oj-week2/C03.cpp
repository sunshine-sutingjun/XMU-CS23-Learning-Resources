#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 9;
int row[N], col[N], block[3][3];
int ones[1 << N], map[1 << N];
string str;
inline int lowbit(int n)
{
    return n & (-n);
}
void init()
{
    for (int i = 0; i < N; i++) row[i] = col[i] = (1 << N) - 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            block[i][j] = (1 << N) - 1;
    }
}
inline int get(int x, int y)
{
    return row[x] & col[y] & block[x / 3][y / 3];
}
bool dfs(int cnt)
{
    if (cnt == 0) return true;
    int x, y;
    int minv = 10;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (str[i * N + j] == '.')
            {
                if (minv > ones[get(i, j)])
                {
                    minv = ones[get(i, j)];
                    x = i;
                    y = j;
                }
            }
        }
    }
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];
        str[x * N + y] = '1' + t;
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        block[x / 3][y / 3] -= 1 << t;
        if (dfs(cnt - 1)) return true;
        str[x * N + y] = '.';
        row[x] += 1 << t;
        col[y] += 1 << t;
        block[x / 3][y / 3] += 1 << t;
    }
    return false;
}
int main()
{
    for (int i = 0; i < N; i++) map[1 << i] = i;
    for (int i = 0; i < 1 << N; i++)
    {
        int s = 0;
        for (int j = i; j; j -= lowbit(j)) s++;
        ones[i] = s;
    }
    while (cin >> str, str[0] != 'e')
    {
        init();
        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++, k++)
            {
                if (str[k] != '.')
                {
                    int x = str[k] - '1';
                    row[i] -= 1 << x;
                    col[j] -= 1 << x;
                    block[i / 3][j / 3] -= 1 << x;
                }
                else cnt++;
            }
        }
        dfs(cnt);
        cout << str << endl;
    }
    return 0;
}