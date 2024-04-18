#include <bits/stdc++.h>

using namespace std;

ll qpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = a * ans;
        a = a * a;
        n >>= 1;
    }
    return ans % mod;
}

ll qpow(ll a, ll n, ll mod)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = a * ans % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans % mod;
}