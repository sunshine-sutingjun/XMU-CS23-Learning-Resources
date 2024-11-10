#include <iostream>
#include <algorithm>
using namespace std;
const int N = 9;
int scores[81];
int row[N], col[N], block[3][3];
int maxsum = 0;
int ones[1 << N], map[1 << N];
int board[N][N];
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
bool dfs(int cnt, int sum)
{
    if (cnt == 0)
    {
        maxsum = max(maxsum, sum);
        return true;
    }
    bool falg = false;
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
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
        board[x][y] = t + 1;
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        block[x / 3][y / 3] -= 1 << t;
        if (dfs(cnt - 1, sum + scores[x * N + y] * board[x][y])) falg = true;
        board[x][y] = 0;
        row[x] += 1 << t;
        col[y] += 1 << t;
        block[x / 3][y / 3] += 1 << t;
    }
    if (!falg)
        return false;
    return true;
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) scores[i * N + j] = 6;
            else if (i == 1 || i == N - 2 || j == 1 || j == N - 2) scores[i * N + j] = 7;
            else if (i == 2 || i == N - 3 || j == 2 || j == N - 3) scores[i * N + j] = 8;
            else if (i == 3 || i == N - 4 || j == 3 || j == N - 4) scores[i * N + j] = 9;
            else scores[i * N + j] = 10;
        }
    }
    init();
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0)
            {
                int x = board[i][j] - 1;
                sum += scores[i * N + j] * board[i][j];
                row[i] -= 1 << x;
                col[j] -= 1 << x;
                block[i / 3][j / 3] -= 1 << x;
            }
            else cnt++;
        }
    }
    if (!dfs(cnt, sum))
        cout << -1 << endl;
    else
        cout << maxsum << endl;
    return 0;
}