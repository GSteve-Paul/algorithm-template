#include <bits/stdc++.h>
// #define int long long
#define rson 2 * k + 1
#define lson 2 * k
#define me k
#define mid (a[me].l + a[me].r) / 2

const int N = 1e6 + 5;

using namespace std;

struct SegmentTree
{
    struct node
    {
        int l, r;
        int sum;
        int lazy;
        node() { l = r = sum = lazy = 0; }
    };

    int num[N];
    node a[4 * N];

    void update(int k)
    {
        a[me].sum = a[lson].sum + a[rson].sum;
    }

    void build(int k, int l, int r)
    // 当前在k上,建树
    {
        a[me].l = l;
        a[me].r = r;
        if (l == r)
        {
            a[me].sum = num[l];
            return;
        }
        build(lson, a[me].l, mid);
        build(rson, mid + 1, a[me].r);
        update(k);
    }

    void pushdown(int k)
    {
        if (a[me].l == a[me].r)
        {
            a[me].lazy = 0;
            return;
        }
        a[lson].sum += (a[lson].r - a[lson].l + 1) * a[me].lazy;
        a[rson].sum += (a[rson].r - a[rson].l + 1) * a[me].lazy;
        a[lson].lazy += a[me].lazy;
        a[rson].lazy += a[me].lazy;
        a[me].lazy = 0;
    }

    int query(int k, int l, int r) // 区间查询
    // 当前在k上,问l~r的和
    {
        if (a[me].lazy)
            pushdown(k);
        if (a[me].l == l && a[me].r == r)
            return a[me].sum;
        if (r <= mid)
            return query(lson, l, r);
        else if (l > mid)
            return query(rson, l, r);
        else
            return query(lson, l, mid) + query(rson, mid + 1, r);
    }

    void changeSegment(int k, int l, int r, int x) // 区间修改
    // 当前在k上,修改l~r,全部加上x
    {
        if (a[k].l == l && a[k].r == r)
        {
            a[k].sum += (r - l + 1) * x;
            a[k].lazy += x;
            return;
        }
        pushdown(k);
        if (r <= mid)
            changeSegment(lson, l, r, x);
        else if (l > mid)
            changeSegment(rson, l, r, x);
        else
        {
            changeSegment(lson, l, mid, x);
            changeSegment(rson, mid + 1, r, x);
        }
        update(k);
    }

    void change(int k, int x, int y)
    // 当前在k上,把第x修改成y
    {
        if (a[me].l == a[me].r)
        {
            a[me].sum = y;
            return;
        }
        if (x <= mid)
            change(lson, x, y);
        else
            change(rson, x, y);
        update(k);
    }
};
// 若有多组样例,记得清空数组a