// BOJ 17070 :: 파이프 옮기기 1
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, ans;
int board[17][17];
struct Pos
{
    int y = 0;
    int x = 0;
    int r = 0;// 0 = 0도, 1 = 45도, 2 = 90도
};
void BFS()
{
    queue<Pos> q;
    Pos pos = { 1,2,0 };
    q.push(pos);
    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        if (pos.y == n && pos.x == n)
        {
            ans++;
            continue;
        }
        if (pos.r == 0)
        {
            int nexty = pos.y;
            int nextx = pos.x + 1;
            if (nextx <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,0 });
            }
            nexty = pos.y + 1;
            nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
        }
        else if (pos.r == 1)
        {
            int nexty = pos.y;
            int nextx = pos.x + 1;
            if (nextx <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,0 });
            }
            nexty = pos.y + 1;
            nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
            nexty = pos.y + 1;
            nextx = pos.x;
            if (nexty <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,2 });
            }
        }
        else if (pos.r == 2)
        {
            int nexty = pos.y + 1;
            int nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
            nexty = pos.y + 1;
            nextx = pos.x;
            if (nexty <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,2 });
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }
    BFS();
    cout << ans;
    return 0;
}