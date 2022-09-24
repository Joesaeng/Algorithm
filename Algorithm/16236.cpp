// BOJ 16236 :: 아기 상어
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int board[21][21];
bool vis[21][21];
int n;
int ans,cnt;
int sSize = 2, eat = 0;
struct baby
{
    int y = 0;
    int x = 0;
    bool cango()
    {
        if (y < 1 || y > n) return false;
        else if (x < 1 || x > n) return false;
        else if (board[y][x] > sSize) return false;
        else if (vis[y][x]) return false;
        return true;
    }
};
void BFS(baby& shark)
{
    queue<baby> q;
    baby s = shark;
    q.push(s);
    board[s.y][s.x] = 0;
    vis[s.y][s.x] = true;
    int dirY[4] = { -1,0,1,0 };
    int dirX[4] = { 0,-1,0,1};// 위 -> 왼-> 아래-> 오른
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            s = q.front();
            q.pop();
            if (board[s.y][s.x] < sSize && board[s.y][s.x] != 0) // 지금 크기보다 작은 물고기라면
            {
                int y=s.y, x=s.x;
                for(int j = i+1; j < qSize; ++j)
                {
                    if (q.empty())continue;
                    int ty = q.front().y; int tx = q.front().x;
                    if (board[ty][tx] < sSize && board[ty][tx] != 0) // 했는데 또 먹을수 있는 물고기가 있다면?
                    {
                        if (ty < y) // 가장 위에 있는 녀석을
                        {
                            y = ty; x = tx; // 먹을 물고기로 결정
                        }
                        else if (ty == y) // 또 다른 물고기중에 같은 y에 있는 녀석이 있다면
                        {
                            if (tx < x) // 가장 왼쪽에 있는 녀석을
                            {
                                y = ty; x = tx; // 먹을 물고기로 결정
                            }
                        }
                    }
                    q.pop();
                }
                s.y = y; s.x = x;
                board[s.y][s.x] = 0; // 먹었다!
                eat++;
                if (eat == sSize) // 먹은 개수가 지금 크기와 같다면
                {
                    sSize++;
                    eat = 0; // 크기를 늘려주고 먹은 개수를 초기화
                }
                ans += cnt; // 경로 더해주기
                cnt = 0;
                qSize = 0;
                while (!q.empty()) q.pop();
                memset(vis, false, sizeof(vis)); // 경로 초기화
            }
            for (int next = 0; next < 4; ++next)
            {
                baby tmp;
                tmp.y = s.y + dirY[next];
                tmp.x = s.x + dirX[next];
                if (!tmp.cango()) continue;
                q.push(tmp);
                vis[tmp.y][tmp.x] = true;
            }
        }
        cnt++;
    }
}
int main()
{
    FASTIO;
    cin >> n;
    baby shark; // 뚜루루뚜루
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark.y = i;
                shark.x = j;
            }
        }
    }
    
    BFS(shark);
    cout << ans;
    return 0;
}