// BOJ 1358 :: гое╟
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
double length(int x, int y, int xx, int yy)
{
    double ret = 0;
    ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
    return ret;
}
int w, h, x, y, p;
int px, py;
int cnt = 0;
int main()
{
    FASTIO;
    cin >> w >> h >> x >> y >> p;
    for (int i = 0; i < p; ++i)
    {
        cin >> px >> py;
        bool in = false;
        if (px >= x && px <= x + w && py >= y && py <= y + h)
            in = true;
        else
        {
            double lLen = length(px, py, x, y + (h / 2));
            double rLen = length(px, py, (x+w), y + (h / 2));
            if (lLen <= (h / 2)) in = true;
            else if (rLen <= (h / 2)) in = true;
        }
        if (in) cnt++;
    }
    cout << cnt;
    return 0;
}