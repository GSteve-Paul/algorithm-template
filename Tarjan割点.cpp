#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e4 + 5;

vector<int> g[maxn];
int dfn[maxn], low[maxn];
int cut[maxn];
int nodecnt;

int n, m;
int root;

void initTarjan()
{
    fill(dfn + 1, dfn + n + 1, -1);
    fill(low + 1, low + n + 1, -1);
    fill(cut + 1, cut + n + 1, 0);
    nodecnt = 0;
}

void Tarjan(int node)
{
    int child = 0;
    nodecnt++;
    dfn[node] = low[node] = nodecnt;
    for (int nei: g[node])
    {
        if (dfn[nei] == -1)
        {
            child++;
            Tarjan(nei);
            low[node] = min(low[node], low[nei]);
            if (low[nei] >= dfn[node] && node != root)
            {
                cut[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node], dfn[nei]);
        }
    }
    if (node == root && child >= 2)
    {
        cut[node] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    initTarjan();
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == -1)
        {
            root = i;
            Tarjan(i);
        }
    }
    int cutcnt = 0;
    for (int i = 1; i <= n; i++)
        cutcnt += cut[i];
    cout << cutcnt << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}