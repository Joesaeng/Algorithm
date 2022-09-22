// BOJ 7569 :: 토마토
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int m, n, h, ans;
struct vec3
{
public:
    int z;
    int y;
    int x;
    bool cannot()
    {
        if (z < 0 || z > h - 1) return false;
        else if (y < 0 || y > n - 1) return false;
        else if (x < 0 || x > m - 1) return false;
        else return true;
    }
};
vector<vector<vector<int>>> vec;
vector<vector<vector<bool>>> vis;
stack<vec3> stk;
queue<vec3> q;
void BFS()
{
    int dirZ[6] = { 1,-1,0,0,0,0 };
    int dirY[6] = { 0,0,1,-1,0,0 };
    int dirX[6] = { 0,0,0,0,1,-1 };
    while (!q.empty())
    {
        int qsize = q.size();
        for (int j = 0; j < qsize; ++j)
        {
            vec3 Pos = q.front();
            q.pop();
            for (int i = 0; i < 6; ++i)
            {
                vec3 nextPos = vec3{ Pos.z + dirZ[i] , Pos.y + dirY[i] , Pos.x + dirX[i] };
                if (!nextPos.cannot()) continue;
                if (vis[Pos.z + dirZ[i]][Pos.y + dirY[i]][Pos.x + dirX[i]]) continue;
                if (vec[Pos.z + dirZ[i]][Pos.y + dirY[i]][Pos.x + dirX[i]] == -1 ||
                    vec[Pos.z + dirZ[i]][Pos.y + dirY[i]][Pos.x + dirX[i]] == 1) continue;
                q.push(nextPos);
                vis[Pos.z + dirZ[i]][Pos.y + dirY[i]][Pos.x + dirX[i]] = true;
            }
        }
        ans++;
    }
}
int main()
{
    FASTIO;
    cin >> m >> n >> h;
    vec = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m)));
    vis = vector<vector<vector<bool>>>(h, vector<vector<bool>>(n, vector<bool>(m,false)));
    for (int zz = 0; zz < h; ++zz)
    {
        for (int yy = 0; yy < n; ++yy)
        {
            for (int xx = 0; xx < m; ++xx)
            {
                cin >> vec[zz][yy][xx];
                if (vec[zz][yy][xx] == 0)
                {
                    stk.push(vec3{ zz,yy,xx });
                }
                else if (vec[zz][yy][xx] == 1)
                {
                    vec3 pos = vec3{ zz,yy,xx };
                    vis[zz][yy][xx] = true;
                    q.push(pos);
                }
            }
        }
    }
    BFS();
    while (!stk.empty())
    {
        vec3 pos = stk.top();
        stk.pop();
        if (vis[pos.z][pos.y][pos.x] == false) // 익지 않았다면(BFS에서 방문하지 않았다면)
        {
            ans = 0; // cnt를 0으로 돌린 후 반복문 탈출
            break;
        }
    }
    cout << ans - 1;
    return 0;
}