// BOJ 1002 :: ≈Õ∑ø
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t;
int x, y, r1, xx, yy, r2;
double length(int x, int y, int xx, int yy)
{
    double ret = 0;
    ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
    return ret;
}
int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> x >> y >> r1 >> xx >> yy >> r2;
        if (x == xx && y == yy)
        {
            if (r1 == r2)
            {
                cout << "-1" << '\n';
                continue;
            }
            else
            {
                cout << "0" << '\n';
                continue;
            }
        }
        double len = length(x, y, xx, yy);
        if (len > r1 + r2)
        {
            cout << "0" << '\n';
        }
        else if (len < r1 + r2)
        {
            if (r1 < r2) swap(r1, r2);
            
            if (r1 > len + r2)
            {
                cout << "0" << '\n';
            }
            else if (r1 < len + r2)
            {
                cout << "2" << '\n';
            }
            else
            {
                cout << "1" << '\n';
            }
        }
        else
        {
            cout << "1" << '\n';
        }
    }
    return 0;
}