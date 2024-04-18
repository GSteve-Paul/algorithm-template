#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
const int maxm = 2e6 + 5;
using namespace std;

struct Edge // u->v,w
{
    int u, v, w;
    bool operator<(const Edge &e) const
    {
        return this->w < e.w;
    }
};
Edge e[maxm];
int fa[maxn];
int n, tot;
void init()
{
    tot = 0;
    n;
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
    }
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    else
    {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

void addEdge(int u, int v, int w)
{
    e[tot++] = {u, v, w};
}

int Kruskal()
{
    sort(e, e + tot);
    int cnt = 1, cost = 0;
    for (int i = 0; i < tot && cnt < n; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            cost += e[i].w;
            cnt++;
        }
    }
    if (cnt == n)
    {
        return cost;
    }
    else
    {
        return -1;
    }
}
