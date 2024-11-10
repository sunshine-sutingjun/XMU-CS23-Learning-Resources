#include <iostream>
using namespace std;
const int N = 1000010;
int a[N];

int quick_select(int a[], int l, int r, int k)
{
    if (l >= r)
    {
        return a[l];
    }
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    if (j - l + 1 >= k)
    {
        return quick_select(a, l, j, k);
    }
    else
    {
        return quick_select(a, j + 1, r, k - j + l - 1);
    }
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    cout << quick_select(a, 0, n - 1, k);
}