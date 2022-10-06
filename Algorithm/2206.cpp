// BOJ 2206 :: 벽 부수고 이동하기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999999999
using namespace std;
int n, m;
string str;
vector<string> vec;
bool discov[1001][1001][2]; // 벽을 부수고 지나갔는지, 아닌지
int ans;
struct Pos
{
    int y = 0;
    int x = 0;
    int c = 0; // 부쉈는가? 1 : 0
    int cnt = 0;
    Pos operator +(Pos& other)
    {
        Pos ret;
        ret.y = y + other.y;
        ret.x = x + other.x;
        ret.c = c;
        ret.cnt = cnt;
        return ret;
    }
};
int func(Pos start)
{
    queue<Pos> q;
    Pos pos = start;
    pos.cnt = 1; // 시작하는 칸을 센다.
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
            return pos.cnt;
        }
        for (int next = 0; next < 4; ++next)
        {
            Pos nextPos = pos + dir[next];
            nextPos.cnt++;
            if (nextPos.y < 1 || nextPos.y > n || nextPos.x < 1 || nextPos.x > m) continue;
            if (vec[nextPos.y][nextPos.x] - '0' == 1 && pos.c == 0) // 다음 자리가 벽이고, 아직 벽을 부수지 않았는지
            {
                discov[nextPos.y][nextPos.x][pos.c + 1] = true;
                nextPos.c = 1;
                q.push(nextPos);
            }
            else if (vec[nextPos.y][nextPos.x] - '0' == 0 && discov[nextPos.y][nextPos.x][pos.c] == false)
            {
                discov[nextPos.y][nextPos.x][pos.c] = true;
                q.push(nextPos);
            }
        }
    }
    return -1;
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
    cout << func(Pos{ 1,1 });
    
    return 0;
}