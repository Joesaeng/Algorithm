// BOJ 17070 :: 파이프 옮기기 1
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, ans;
int board[17][17]; // 빈칸과 벽의 위치를 받을 배열
struct Pos
{
    // 각 칸에 파이프가 이어질 때, 위치와 이은 각도를 저장하는 구조체
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
            continue; // 방법을 찾았다면 다음으로 진행
        }
        if (pos.r == 0) // 현재 파이프의 각도가 0도일때, 우측과 우하단으로 이동 가능
        {
            // 우측으로 한칸 이동하는 경우
            int nexty = pos.y;
            int nextx = pos.x + 1; 
            if (nextx <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,0 });
            }
            // 우하단으로 이동하는 경우
            nexty = pos.y + 1;
            nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
        }
        else if (pos.r == 1) // 45도 일때, 우측,우하단,아래칸으로 이동 가능
        {
            // 우측으로 한칸 이동하는 경우
            int nexty = pos.y;
            int nextx = pos.x + 1;
            if (nextx <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,0 });
            }
            // 우하단으로 이동하는 경우
            nexty = pos.y + 1;
            nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
            // 아래칸으로 이동하는 경우
            nexty = pos.y + 1;
            nextx = pos.x;
            if (nexty <= n && board[nexty][nextx] == 0)
            {
                q.push({ nexty,nextx,2 });
            }
        }
        else if (pos.r == 2) // 90도일때, 우하단,아래칸으로 이동 가능
        {
            // 우하단으로 이동하는 경우
            int nexty = pos.y + 1;
            int nextx = pos.x + 1;
            if (nexty <= n && nextx <= n &&
                board[nexty - 1][nextx] == 0 && board[nexty][nextx] == 0 && board[nexty][nextx - 1] == 0)
            {
                q.push({ nexty,nextx,1 });
            }
            // 아래칸으로 이동하는 경우
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