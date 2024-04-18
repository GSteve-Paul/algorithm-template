using ll = long long;
const int maxn = 1e5 + 10;
int n;
ll tr[maxn];
int lowbit(int x) { return x & (-x); }
void add(int x, ll c) // 单点修改
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
ll sum(int x) // 区间查询 [1,x]
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
ll sum(int x, int y)
{
    return sum(y) - sum(x - 1);
}