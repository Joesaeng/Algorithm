// BOJ 15812 :: 침략자 진아
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, town = 0, ans = 99999999;
int board[20][20];
string s;
struct pos
{
    int y = 0;
    int x = 0;
};
vector<pos> vec;
int func(pos a, pos b)
{
    queue<pos> q;
    q.push(a);
    q.push(b);
    int t = town;
    int cnt = 0;
    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };
    bool vis[20][20] = { false, };
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; ++i)
        {
            pos Pos = q.front();
            q.pop();
            if (board[Pos.y][Pos.x] == 1) // 독주머니를 통해 마을이 중독됬다!
            {
                t--; // 중독되지 않은 마을의 개수
                if (t == 0) // 전부 중독됬다면
                {
                    return cnt;
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                pos next = { Pos.y + dy[i],Pos.x + dx[i] };
                if (vis[next.y][next.x]) continue;
                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
                q.push(next);
                vis[next.y][next.x] = true;
            }
        }
        cnt++;
    }
}
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = s[j]-'0';
            if (board[i][j] == 1)
                town++; // 마을의 개수
            else
                vec.push_back({ i,j }); // 독주머니를 놓을 수 있는 자리
        }
    }
    // 마을이 없는(독주머니를 놓을 수 있는 자리) 에 두개의 독주머니를 놓는 모든 경우
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            ans = min(ans,func(vec[i],vec[j]));
        }
    }
    cout << ans;
    return 0;
}