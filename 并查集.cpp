#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
using namespace std;

int fa[maxn];
int rk[maxn];

void init()
{
    for (int i = 1; i <= maxn; i++)
    {
        fa[i] = i;
        rk[i] = 0;
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
    fa[find(y)] = find(x);
}

void merge(int x, int y)
{
    int xfa = find(x);
    int yfa = find(y);
    if (rk[xfa] <= rk[yfa])
    {
        fa[xfa] = yfa;
    }
    else
    {
        fa[yfa] = xfa;
    }
    if (rk[xfa] == rk[yfa] && xfa != yfa)
    {
        rk[yfa]++;
    }
}