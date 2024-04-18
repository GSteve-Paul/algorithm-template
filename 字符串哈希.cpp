#include <bits/stdc++.h>

const int maxn = 1e6 + 5;
const int base = 131;
const int mod = 1e9 + 9;

using namespace std;
using uint = unsigned long long;

uint hs[maxn], p[maxn];

void init()
{
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        p[i] = p[i - 1] * base % mod;
    }
}

void Hash(string s) // 将一个字符串看作base进制数
{
    s = " " + s;
    int len = s.length();
    hs[0] = 0;
    for (int i = 1; i < len; i++)
    {
        hs[i] = (hs[i - 1] * base + s[i] - 'a' + 1) % mod;
    }
}

uint getSectionHash(int l, int r) //[l,r]
{
    return (hs[r] - hs[l - 1] * p[r - l + 1] % mod + mod) % mod;
}