#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[14];
int cnt;
bool is_placed(int row, int col)
{
    for (int i = 1; i < row; i++)
        if (col == a[i] || abs(col - a[i]) == abs(row - i))
            return false;
    return true;
}
void dfs(int row)
{
    if (row == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
        cnt++;
        return;
    }
    for (int col = 1; col <= n; col++)
        if (is_placed(row, col))
        {
            a[row] = col;
            dfs(row + 1);
            a[row] = 0;
        }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}