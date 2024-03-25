#include <stdio.h>
int main()
{
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF)
    {
        int th[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &th[i][j]);
            }
        }
        printf("%d ", th[0][0]);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", th[0][i]);
        }
        printf("%d\n", th[0][n - 1]);
        for (int i = 0; i < m; i++)
        {
            printf("%d ", th[i][0]);
            for (int j = 0; j < n; j++)
            {
                printf("%d ", th[i][j]);
            }
            printf("%d\n", th[i][n - 1]);
        }
        printf("%d ", th[m - 1][0]);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", th[m - 1][i]);
        }
        printf("%d\n", th[m - 1][n - 1]);
    }
}