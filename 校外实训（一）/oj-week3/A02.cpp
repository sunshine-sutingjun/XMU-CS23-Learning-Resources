#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 60;
bool b[N][N];
int get_int_sum(int x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}
int bfs(int k, int m, int n)
{
    int count = 0;
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            int x = i + dx[a], y = j + dy[a];
            if (x >= 0 && x < m && y >= 0 && y < n && b[x][y] == 1 && get_int_sum(x) + get_int_sum(y) <= k)
            {
                b[x][y] = 0;
                q.push({ x,y });
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n, m, k;
    cin >> k >> m >> n;
    memset(b, 1, sizeof(b));
    cout << bfs(k, m, n);
    return 0;
}