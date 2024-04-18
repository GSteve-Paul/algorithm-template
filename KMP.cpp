#include <bits/stdc++.h>

using namespace std;

/*
 * 使用方法：
 * 1.  KMP obj = KMP(p,s)进行初始化操作(计算长度，构建next[]数组)
 * 2.  obj.kmp()返回一个vector<int>的引用，表示p在s中出现的地方
 */
struct KMP
{
    /*
     * 下标都从0开始
     */
    int plen, slen;
    string &p, &s;
    vector<int> nxt;

    /*
     * 获取nxt[]数组
     * nxt[i]表示的是如果在i处失配，则让p[nxt[i]]来继续配对
     * 实际上就是p[0,i)中的最长相等前后缀
     * 其中在plen处失配，相当于是在s中已经配完了一个p
     * 其中在0处失配，相当于把p整体向后移动一格
     */
    void getNxt()
    {
        nxt[0] = -1;
        for (int i = 1; i <= plen; i++)
        {
            int j = i - 1;
            int k = nxt[j];
            while (p[k] != p[j] && k != -1)
                k = nxt[k];
            nxt[i] = k + 1;
        }
    }

    /*
     * return p在s中出现的所有位置
     */
    vector<int> &kmp()
    {
        static vector<int> asw;
        int i = 0, j = 0;
        while (i < slen)
        {
            if (j < plen && s[i] == p[j])
            {
                i++;
                j++;
                if (j == plen)
                {
                    asw.push_back(i - plen);
                }
            }
            else
            {
                if (nxt[j] == -1)
                {
                    i++;
                    j = 0;
                }
                else
                {
                    j = nxt[j];
                }
            }
        }
        return asw;
    }

    KMP(string &p, string &s) : p(p), s(s)
    {
        plen = p.length();
        slen = s.length();
        nxt = vector<int>(plen + 5);
        getNxt();
    }
};