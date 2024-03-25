#include <bits/stdc++.h>
using namespace std;
#define N 100010

double GPA(double num)
{
    if (num >= 90)
        return 4.0;
    else if (num >= 85 && num <= 89)
        return 3.7;
    else if (num >= 81 && num <= 84)
        return 3.3;
    else if (num >= 78 && num <= 80)
        return 3.0;
    else if (num >= 75 && num <= 77)
        return 2.7;
    else if (num >= 72 && num <= 74)
        return 2.3;
    else if (num >= 68 && num <= 71)
        return 2.0;
    else if (num >= 64 && num <= 67)
        return 1.7;
    else if (num >= 60 && num <= 63)
        return 1.0;
    else
        return 0.0;
}

double ans = 0;
int n;

int a[N], id = 0;

int main()
{
    while (cin >> n)
    {
        ans = 0;
        if (n <= 59)
        {
            puts("0.0");
            continue;
        }
        for (int i = 60; i <= 100; i++)
        {
            if (i <= n)
            {
                ans = max(ans, GPA(i));
            }
            for (int j = 60; j <= 100; j++)
            {
                if (i + j <= n)
                {
                    ans = max(ans, GPA(i) + GPA(j));
                }
                for (int k = 60; k <= 100; k++)
                {
                    if (i + j + k <= n)
                        ans = max(ans, GPA(i) + GPA(j) + GPA(k));
                    int h = n - i - j - k;
                    if (h > 0 && i + j + k + h <= n)
                    {
                        ans = max(ans, GPA(i) + GPA(j) + GPA(k) + GPA(h));
                    }
                }
            }
        }
        printf("%.1lf\n", ans);
    }
    return 0;
}