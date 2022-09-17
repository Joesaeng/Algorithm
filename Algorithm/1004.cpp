// BOJ 1004 ::  ¾î¸° ¿ÕÀÚ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
double length(int x, int y, int xx, int yy)
{
    double ret = 0;
    ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
    return ret;
}
int t, c;
int x, y, xx, yy;
int cx, cy, r;
int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int cnt = 0;
        cin >> x >> y >> xx >> yy;
        cin >> c;
        for (int j = 0; j < c; ++j)
        {
            cin >> cx >> cy >> r;
            double sLen = length(x, y, cx, cy);
            double eLen = length(xx, yy, cx, cy);
            bool s = sLen < r ? true : false;
            bool e = eLen < r ? true : false;
            if (s && e) continue;
            if (s) cnt++;
            if (e) cnt++;
        }
        cout << cnt << '\n';
    }


    return 0;
}