#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define V2surArea(r,v) (2*v/r)
#define INF 0x7fffffff
int V, N, minsurArea = INF;
int summinS[27], summinV[27];
void dfs(int iFloor, int preR, int preH, int leftV, int surArea)
{
    if (iFloor == 0)
    {
        if (leftV == 0 && surArea < minsurArea)
        {
            minsurArea = surArea;
        }
        return;
    }
    if (preR > 1 && V2surArea(preR - 1, leftV) + surArea >= minsurArea) return;
    if (leftV < summinV[iFloor]) return;
    if (surArea + summinS[iFloor] >= minsurArea) return;
    for (int i = preR - 1; i >= iFloor; i--)
    {
        if (iFloor == N) surArea = i * i;
        int H_max = (1.0 * leftV / (i * i)) + 1;
        if (H_max > preH - 1) H_max = preH - 1;
        for (int j = H_max; j >= iFloor; j--)
        {
            dfs(iFloor - 1, i, j, leftV - i * i * j, surArea + 2 * i * j);
        }
    }
}
int main()
{
    cin >> V >> N;
    summinS[0] = summinV[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        summinS[i] = summinS[i - 1] + i * i * 2;
        summinV[i] = summinV[i - 1] + i * i * i;
    }
    int maxH = (V - summinV[N - 1]) / (N * N) + 1;
    int minR = sqrt(double((V - summinV[N - 1]) + 1));
    minsurArea = INF;
    dfs(N, minR, maxH, V, 0);
    if (minsurArea == INF)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << minsurArea << endl;
    }
    return 0;
}