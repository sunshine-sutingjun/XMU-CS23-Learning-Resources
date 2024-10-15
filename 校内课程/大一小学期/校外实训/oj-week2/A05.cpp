#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
const int N = 100010;
int a[N], temp[N];
long long ans = 0;
long long merge_sort(int a[], int l, int r)
{
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    long long res = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        a[i] = temp[j];
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << merge_sort(a, 0, n - 1) << endl;
    return 0;
}