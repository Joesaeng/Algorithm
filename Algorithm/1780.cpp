// BOJ 1780 :: 종이의 개수
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int N;
int board[2199][2199];
int ans[3];
void cut(int sy,int sx,int n)
{
    int st = board[sy][sx];
    if (n == 1)
    {
        ans[st + 1]++;
        return;
    }
    for (int i = sy; i < sy + n; ++i)
    {
        for (int j = sx; j < sx + n; ++j)
        {
            if (board[i][j] != st)
            {
                int next = n / 3;
                cut(sy, sx, next);
                cut(sy + next, sx, next);
                cut(sy + (2 * next), sx, next);
                cut(sy, sx + next, next);
                cut(sy, sx + (2 * next), next);
                cut(sy + next, sx + next, next);
                cut(sy + next, sx + (2 * next), next);
                cut(sy + (2 * next), sx + next, next);
                cut(sy + (2 * next), sx + (2 * next), next);
                return;
            }
        }
    }
    ans[st + 1]++;
    return;
}
int main()
{
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
        }
    }
    cut(1, 1, N);
    cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
    return 0;
}