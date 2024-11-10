#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
const int N = 510;
int dxyz[4][3][3] = { {{-2,0,2},{-1,0,1},{-1,0,0}},
                   {{1,0,2},{1,0,1},{2,0,0}},
                   {{0,-2,1},{0,-1,0},{0,-1,2}},
                   {{0,1,1},{0,2,0},{0,1,2}} };

struct Stone
{
    int x, y, status;
    Stone(int a, int b, int c) :x(a), y(b), status(c) {}
    Stone() :x(0), y(0), status(0) {};
};

int n, m;
char area[N][N];
int dist[N][N][3];
queue<Stone> q;
Stone start, target;


void dispalyStone(const Stone& p)
{
    cout << "(" << p.x << "," << p.y << "," << p.status << ")" << endl;
}

Stone moveStone(Stone& p, int i)
{
    int x = p.x + dxyz[i][p.status][0];
    int y = p.y + dxyz[i][p.status][1];
    int status = dxyz[i][p.status][2];
    return Stone(x, y, status);
}

bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isValid(Stone t)
{
    if (!isInside(t.x, t.y) || area[t.x][t.y] == '#') return false;
    if (t.status == 0 && area[t.x][t.y] == 'E') return false;
    if (t.status == 1 && (!isInside(t.x, t.y + 1) || area[t.x][t.y + 1] == '#')) return false;
    if (t.status == 2 && (!isInside(t.x + 1, t.y) || area[t.x + 1][t.y] == '#')) return false;
    return true;
}

bool isVisted(Stone t)
{
    return dist[t.x][t.y][t.status] != -1;
}

void BuildMap(int n, int m)
{
    memset(area, '#', sizeof area);
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) cin >> area[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t = area[i][j];
            if (t == 'X')
            {
                start.x = i;
                start.y = j;
                start.status = 0;
                area[i][j] = '.';
                if (isInside(i, j + 1) && area[i][j + 1] == 'X')
                {
                    start.status = 1;
                    area[i][j + 1] = '.';
                }
                if (isInside(i + 1, j) && area[i + 1][j] == 'X')
                {
                    start.status = 2;
                    area[i + 1][j] = '.';
                }
            }
            if (t == 'O')
            {
                target.x = i;
                target.y = j;
                target.status = 0;
            }
        }
    }
}

int bfs(Stone& s)
{
    while (!q.empty()) q.pop();
    q.push(s);
    dist[s.x][s.y][s.status] = 0;
    while (!q.empty())
    {
        Stone t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Stone s = moveStone(t, i);
            if (!isValid(s))
                continue;
            if (!isVisted(s))
            {
                dist[s.x][s.y][s.status] = dist[t.x][t.y][t.status] + 1;
                q.push(s);
                if (s.x == target.x && s.y == target.y && s.status == target.status)
                    return dist[s.x][s.y][s.status];
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> n >> m && n)
    {
        BuildMap(n, m);
        int res = bfs(start);
        if (res == -1)
            cout << "Impossible" << endl;
        else
            cout << res << endl;
    }
    return 0;
}