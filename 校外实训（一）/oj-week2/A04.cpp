#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
void Mergesort(int a[], int l, int r)
{
    if (l == r)
        return;
    int mid = l + r >> 1;
    Mergesort(a, l, mid);
    Mergesort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int tmp[N];
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}