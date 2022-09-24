// BOJ 16236 :: �Ʊ� ���
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
    int dirX[4] = { 0,-1,0,1};// �� -> ��-> �Ʒ�-> ����
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            s = q.front();
            q.pop();
            if (board[s.y][s.x] < sSize && board[s.y][s.x] != 0) // ���� ũ�⺸�� ���� �������
            {
                int y=s.y, x=s.x;
                for(int j = i+1; j < qSize; ++j)
                {
                    if (q.empty())continue;
                    int ty = q.front().y; int tx = q.front().x;
                    if (board[ty][tx] < sSize && board[ty][tx] != 0) // �ߴµ� �� ������ �ִ� ����Ⱑ �ִٸ�?
                    {
                        if (ty < y) // ���� ���� �ִ� �༮��
                        {
                            y = ty; x = tx; // ���� ������ ����
                        }
                        else if (ty == y) // �� �ٸ� ������߿� ���� y�� �ִ� �༮�� �ִٸ�
                        {
                            if (tx < x) // ���� ���ʿ� �ִ� �༮��
                            {
                                y = ty; x = tx; // ���� ������ ����
                            }
                        }
                    }
                    q.pop();
                }
                s.y = y; s.x = x;
                board[s.y][s.x] = 0; // �Ծ���!
                eat++;
                if (eat == sSize) // ���� ������ ���� ũ��� ���ٸ�
                {
                    sSize++;
                    eat = 0; // ũ�⸦ �÷��ְ� ���� ������ �ʱ�ȭ
                }
                ans += cnt; // ��� �����ֱ�
                cnt = 0;
                qSize = 0;
                while (!q.empty()) q.pop();
                memset(vis, false, sizeof(vis)); // ��� �ʱ�ȭ
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
    baby shark; // �ѷ��ѷ�
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