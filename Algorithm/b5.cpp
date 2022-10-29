// BOJ 0 ::
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int a, b, c, t;
int main()
{
    FASTIO;
    cin >> a >> b >> c >> t;
    if (t > 86400)
    {
        t %= 86400;
    }
    if (t > 3600)
    {
        a += t / 3600;
        if (a >= 24)
            a %= 24;
        t %= 3600;
    }
    if (t > 60)
    {
        b += t / 60;
        if (b >= 60)
        {
            b %= 60;
            a += 1;
            if (a >= 24)
                a %= 24;
        }
        t %= 60;
    }
    c += t;
    if (c >= 60)
    {
        c %= 60;
        b += 1;
        if (b >= 60)
        {
            b %= 60;
            a += 1;
            if (a >= 24)
                a %= 24;
        }
    }
    cout << a << ' ' << b << ' ' << c << ' ';

    
    return 0;
}