#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int main()
{
    int a[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    sort(a, a + n);
    for (int i = 0; i < k; i++)
    {
        cout << a[n - i - 1] << endl;
    }
    return 0;
}