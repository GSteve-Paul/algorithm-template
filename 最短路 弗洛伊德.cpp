#include <bits/stdc++.h>

const int maxn = 505;

using namespace std;

int dist[maxn][maxn];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
}