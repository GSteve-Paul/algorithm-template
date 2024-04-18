#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;

int n, m;
vector<int> g[maxn];
stack<int> stk;
int dfn[maxn];
int low[maxn];
int col[maxn];
int nodecnt;
int scccnt;

void initTarjan()
{
    fill(dfn + 1, dfn + n + 1, -1);
    fill(col + 1, col + n + 1, -1);
    nodecnt = 0;
    scccnt = 0;
}

void Tarjan(int node)
{
    nodecnt++;
    dfn[node] = low[node] = nodecnt;
    stk.push(node);
    for (int elem : g[node])
    {
        if (dfn[elem] == -1)
        {
            Tarjan(elem);
            low[node] = min(low[node], low[elem]);
        }
        else if (col[elem] == -1)
        {
            low[node] = min(low[node], dfn[elem]);
        }
    }
    if (low[node] == dfn[node])
    {
        scccnt++;
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            col[v] = scccnt;
        } while (v != node);
    }
}

struct Lijn
{
    int mn = 1e9;
    vector<int> ans;
};
Lijn lijn[maxn];

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
    }
    initTarjan();
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] != -1)
            continue;
        Tarjan(i);
    }
    cout << scccnt << "\n";
    for (int i = 1; i <= n; i++)
    {
        lijn[col[i]].ans.push_back(i);
        lijn[col[i]].mn = min(lijn[col[i]].mn, i);
    }
    sort(lijn + 1, lijn + scccnt + 1, [](const Lijn &o1, const Lijn &o2) -> bool
         { return o1.mn < o2.mn; });
    for (int i = 1; i <= scccnt; i++)
    {
        sort(lijn[i].ans.begin(), lijn[i].ans.end());
        for (int ele : lijn[i].ans)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}