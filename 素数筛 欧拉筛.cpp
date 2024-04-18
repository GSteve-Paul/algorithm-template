#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bitset<N> v;
vector<int> p(1);
int cnt = 0;

void Euler_seive()
{
    for (int i = 2; i < N; ++i)
    {
        if (!v[i])
        {
            p.push_back(i);
            cnt++;
        }
        for (int j = 1; j <= cnt && i * p[j] < N; ++j)
        {
            v[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }
}