#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
                cout << arr[i] << " ";
            else
                cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}