#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

ll modinv(ll a, ll p)
{
    ll x, y;
    ll gcd = exgcd(a, p, x, y);
    if (gcd != 1)
        return -1;
    else
        return (x % p + p) % p;
}