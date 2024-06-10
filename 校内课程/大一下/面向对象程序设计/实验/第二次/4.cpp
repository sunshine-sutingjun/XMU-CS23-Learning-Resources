#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long

ll a[N];
int n;

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        ll ans = -1;
        // Use a two-pointer approach to find the best third side
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                ll sum = a[i] + a[j];
                // Find the rightmost value less than the sum of a[i] and a[j]
                int k = upper_bound(a + j + 1, a + n + 1, sum - 1) - a - 1;
                if (k > j) { // Ensure it forms a valid triangle
                    ans = max(ans, sum + a[k]);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
