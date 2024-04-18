#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5;

int n, m;

vector<int> g[maxn];
int dfn[maxn];
int low[maxn];
vector<pair<int, int>> cutedge;
int nodecnt;
int root;

void initTarjan()
{
    fill(dfn + 1, dfn + n + 1, -1);
    fill(low + 1, low + n + 1, -1);
    nodecnt = 0;
}

void Tarjan(int node, int fa = 0)
{
    int child = 0;
    nodecnt++;
    dfn[node] = low[node] = nodecnt;
    for (int nei : g[node])
    {
        if (nei == fa)
            continue;
        if (dfn[nei] == -1)
        {
            child++;
            Tarjan(nei, node);
            low[node] = min(low[node], low[nei]);
            if (low[nei] > dfn[node])
            {
                cutedge.push_back({nei, node});
            }
        }
        else
        {
            low[node] = min(low[node], dfn[nei]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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
    cout << cutedge.size() << "\n";
    return 0;
}
