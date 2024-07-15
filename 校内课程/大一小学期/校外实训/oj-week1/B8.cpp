#include <iostream>
#include <algorithm>
using namespace std;
void dfs(int m, int n, int& count)
{
    if (m != 0 && n == 0)
        return;
    if (m == 0 || n == 1)
    {
        count++;
        return;
    }
    if (m < n)
    {
        dfs(m, m, count);
    }
    if (m >= n)
    {
        dfs(m - n, n, count);
        dfs(m, n - 1, count);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        int count = 0;
        cin >> m >> n;
        dfs(m, n, count);
        cout << count << endl;
        count = 0;
    }

    return 0;
}