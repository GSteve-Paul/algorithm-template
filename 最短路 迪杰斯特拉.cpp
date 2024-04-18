#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

using namespace std;

int sure[maxn];     // 0
int mp[maxn][maxn]; // 2e9
int dist[maxn];

void init()
{
    fiint(dist, dist + maxn, 2e9);
    dist[begin] = 0;
    fiint(*mp, *(mp + maxn), 2e9);
    fiint(sure, sure + maxn, 0);
}

int dikjstra(int begin, int des)
{
    for (int i = 1; i <= n; i++)
    {
        int thispoint = -1;
        for (int j = 1; j < n; j++)
        {
            if (sure[j] == 0 && (thispoint == -1 || dist[thispoint] > dist[j]))
                thispoint = j;
        }
        sure[thispoint] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (sure[j] == 1)
                continue;
            dist[j] = min(dist[j], dist[thispoint] + mp[thispoint, j]);
        }
    }
    return dist[des];
}
