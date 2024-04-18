#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int maxm = 4;

int f[maxm]{1, 4, 16, 64}; // 改变当前状态的方式,确保是单增的
int sg[maxn];              // 状态0~n的sg函数值
int s[maxn];               // 后继状态的集合

void getsg(int n)
{
    fill(sg, sg + maxn, 0);
    for (int i = 1; i <= n; i++)
    {
        fill(s, s + maxn, 0);
        for (int j = 0; j < maxm && i - f[j] >= 0; j++)
        {
            s[sg[i - f[j]]] = 1;
        }
        for (int j = 0; j < maxn; j++)
        {
            if (s[j] == 0)
            {
                sg[i] = j;
                break;
            }
        }
    }
}

int main()
{
    getsg(20);
    return 0;
}