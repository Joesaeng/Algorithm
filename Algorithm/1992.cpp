// BOJ 1992 :: ÄõµåÆ®¸®
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
string vec[64];
void quad(int sy, int sx, int n)
{
    int x = vec[sy][sx] - '0';
    if (n == 1)
    {
        cout << x;
        return;
    }
    for (int i = sy; i < sy + n; ++i)
    {
        for (int j = sx; j < sx + n; ++j)
        {
            if (vec[i][j] - '0' != x)
            {
                int next = n / 2;
                cout << '(';
                quad(sy, sx, next);
                quad(sy, sx + next, next);
                quad(sy + next, sx, next);
                quad(sy + next, sx + next, next);
                cout << ')';
                return;
            }
        }
    }
    cout << x;
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    quad(0, 0, n);
    return 0;
}