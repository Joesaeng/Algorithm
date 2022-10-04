// BOJ 2206 :: 벽 부수고 이동하기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999999999
using namespace std;
int n, m;
string str;
vector<string> vec;
bool discov[1001][1001][2];
int ans;
struct Pos
{
    int y = 0;
    int x = 0;
    int c = 0;
    int cnt = 0;
    Pos operator +(Pos& other)
    {
        Pos ret;
        ret.y = y + other.y;
        ret.x = x + other.x;
        return ret;
    }
};
bool func(Pos start)
{
    queue<Pos> q;
    Pos pos = start;
    pos.cnt = 1;
    q.push(pos);
    discov[pos.y][pos.x][0] = true;
    Pos dir[4] =
    {
        Pos{1,0},
        Pos{-1,0},
        Pos{0,1},
        Pos{0,-1}
    };
    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        if (pos.y == n && pos.x == m)
        {
            ans = pos.cnt;
            return true;
        }
        if(pos.c == 0)
        for (int next = 0; next < 4; ++next)
        {
            Pos nextPos = pos + dir[next];
            if (nextPos.y < 1 || nextPos.y > n || nextPos.x < 1 || nextPos.x > m) continue;
            if (discov[nextPos.y][nextPos.x][0]) continue;
            if (vec[nextPos.y][nextPos.x] - '0' == 0)
            {
                discov[nextPos.y][nextPos.x][0] = true;
                nextPos.cnt = pos.cnt + 1;
                q.push(nextPos);
            }
            else
            {
                discov[nextPos.y][nextPos.x][1] = true;
                nextPos.cnt = pos.cnt + 1;
                nextPos.c = 1;
                q.push(nextPos);
            }
        }
        else
        {
            for (int next = 0; next < 4; ++next)
            {
                Pos nextPos = pos + dir[next];
                if (nextPos.y < 1 || nextPos.y > n || nextPos.x < 1 || nextPos.x > m) continue;
                if (discov[nextPos.y][nextPos.x][1]) continue;
                if (discov[nextPos.y][nextPos.x][0]) continue;
                if (vec[nextPos.y][nextPos.x] - '0' == 0)
                {
                    discov[nextPos.y][nextPos.x][1] = true;
                    nextPos.cnt = pos.cnt + 1;
                    nextPos.c = 1;
                    q.push(nextPos);
                }
            }
        }
    }
    return false;
}

int main()
{
    FASTIO;
    cin >> n >> m;
    vec = vector<string>(n + 1,"9");
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        vec[i] += str;
    }
    if (func(Pos{ 1,1 })) cout << ans;
    else cout << "-1";
    
    return 0;
}