// BOJ 1074 :: Z
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, r, c;
long long ans = 0;
bool b;
void Z(int sY, int sX, int nn)
{
    if (b) return;
    int N = pow(2, nn);
    int dirY[4] = { 0,0,1,1 };
    int dirX[4] = { 0,1,0,1 };
    for (int i = 0; i < 4; ++i)
    {
        int nextY = sY + dirY[i];
        int nextX = sX + dirX[i];
        if (nextY == r && nextX == c)
        {
            cout << ans;
            b = true;
            return;
        }
        ans++;
    }
}
void search(int sY, int sX, int nn)
{
    if (b) return;
    if ((sY == r || sY == r - 1) && (sX == c || sX == c - 1))
    {
        Z(sY,sX,nn);
    }
    else if (nn > 1)
    {
        int N = pow(2, nn - 1);
        if(r < sY + N && c < sX + N)
            search(sY, sX, nn - 1);
        else if (r < sY + N && c >= sX + N)
        {
            ans += pow(N, 2);
            search(sY, sX + N, nn - 1);
        }
        else if (r >= sY + N && c < sX + N)
        {
            ans += 2 * pow(N, 2);
            search(sY + N, sX, nn - 1);
        }
        else if (r >= sY + N && c >= sX + N)
        {
            ans += 3 * pow(N, 2);
            search(sY + N, sX + N, nn - 1);
        }
    }
}
int main()
{
    FASTIO;
    cin >> n >> r >> c;
    search(0, 0, n);
    return 0;
}