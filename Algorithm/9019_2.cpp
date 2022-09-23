// BOJ 9019 :: DSLR
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, A, B;
pair<int, char> parentS[10000];
pair<int, char> parentE[10000];
vector<int> vis(10000, 0);

int D(int a)
{
    return (a * 2) % 10000;
}
int S(int a)
{
    if (a == 0) return 9999;
    else return a - 1;
}
int L(int a)
{
    int ret = (a % 1000) * 10 + a / 1000;
    return ret;
}
int R(int a)
{
    int ret = (a % 10) * 1000 + a / 10;
    return ret;
}
int fD1(int a)
{
    int ret = (a + 10000) / 2;
    return ret;
}
int fD2(int a)
{
    int ret = a / 2;
    return ret;
}
int fS(int a)
{
    if (a == 9999) return 0;
    else return a + 1;
}
int fL(int a)
{
    int ret = (a % 10) * 1000 + a / 10;
    return ret;
}
int fR(int a)
{
    int ret = (a % 1000) * 10 + a / 1000;
    return ret;
}
void func()
{
    queue<int> sq;
    queue<int> eq;
    string str;
    vis = vector<int>(10000, 0);
    bool b = false;
    int start = A;
    int end = B;
    int sfind = -1, efind = -1;
    sq.push(start);
    eq.push(end);
    parentS[start] = pair{ start,'0' };
    parentE[end] = pair{ end,'0' };
    vis[start] = 1;
    vis[end] = 2;
    while (!b && !sq.empty() || !eq.empty())
    {
        int sqsize = sq.size();
        for (int i = 0; i < sqsize; ++i)
        {
            if (b) break;
            int t = sq.front();
            sq.pop();
            int dslr[4] = { D(t),S(t),L(t),R(t) };
            for (int j = 0; j < 4; ++j)
            {
                char x = j == 0 ? 'D' : j == 1 ? 'S' : j == 2 ? 'L' : 'R';
                if (vis[dslr[j]] == 0)
                {
                    vis[dslr[j]] = 1;
                    sq.push(dslr[j]);
                    parentS[dslr[j]] = pair{ t,x };
                }
                else if (vis[dslr[j]] == 2)
                {
                    parentS[dslr[j]] = pair{ t,x };
                    sfind = dslr[j];
                    b = true;
                    while (!sq.empty()) sq.pop();
                    while (!eq.empty()) eq.pop();
                    break;
                }
            }
        }
        if (!eq.empty())
        {
            int eqsize = eq.size();
            for (int i = 0; i < eqsize; ++i)
            {
                if (b) break;
                int t = eq.front();
                eq.pop();
                int slr[5] = { fD1(t),fD2(t),fS(t),fL(t),fR(t) };
                int j = 0;
                if (t % 2 == 0) j = 0;
                else j = 2;
                for (; j < 5; ++j)
                {
                    char x = j == 0 ? 'D' : j == 1 ? 'D' : j == 2 ? 'S' : j == 3 ? 'L' : 'R';
                    if (vis[slr[j]] == 0)
                    {
                        vis[slr[j]] = 2;
                        eq.push(slr[j]);
                        parentE[slr[j]] = pair{ t,x };
                    }
                    else if (vis[slr[j]] == 1)
                    {
                        parentE[slr[j]] = pair{ t,x };
                        efind = slr[j];
                        b = true;
                        while (!sq.empty()) sq.pop();
                        while (!eq.empty()) eq.pop();
                        break;
                    }
                }
            }
        }
    }
    int xfind = sfind != -1 ? sfind : efind;

    int s = xfind;
    int e = xfind;
    while (parentS[s].first != s)
    {
        str += parentS[s].second;
        s = parentS[s].first;
    }
    reverse(str.begin(), str.end());
    while (parentE[e].first != e)
    {
        str += parentE[e].second;
        e = parentE[e].first;
    }


    for (auto a : str)
        cout << a;
    cout << '\n';
}

int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> A >> B;
        func();
    }
    return 0;
}