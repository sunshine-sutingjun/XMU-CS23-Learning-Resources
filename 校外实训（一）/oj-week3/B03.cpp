#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define PII pair<int,int>
const int N = 150010;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({ 0,1 });
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int ver = t.second, distance = t.first;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int j = h[ver]; j != -1; j = ne[j])
        {
            int jver = e[j];
            if (dist[jver] > distance + w[j])
            {
                dist[jver] = distance + w[j];
                pq.push({ dist[jver],jver });
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}