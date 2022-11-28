// BOJ 17144 :: 미세먼지 안녕!
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
pair<int, int> topAir;
pair<int, int> downAir; // 공기청정기 위치
bool bTop;
int r, c, t;// r*c 행렬 t초
struct Pos
{
    int y = 0;
    int x = 0;
    int dust = 0; // 좌표와 그 좌표에 있는 먼지의 양
};
vector<vector<int>> vec;
queue<Pos> q;
void func()
{
    int tempT = 0;
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };
    while (tempT < t) // t초가 지날때까지 공기청정기를 돌린다
    {
        while (!q.empty()) // 미세먼지 확산
        {
            Pos pos = q.front();
            int cnt = 0;
            q.pop();
            for (int i = 0; i < 4; ++i) // 각 방향으로 먼지가 확산한다
            {
                int nexty = pos.y + dy[i];
                int nextx = pos.x + dx[i];
                if (nexty < 0 || nexty >= r || nextx < 0 || nextx >= c) continue;
                if (vec[nexty][nextx] == -1) continue; // 확산 가능한지 체크
                vec[nexty][nextx] += pos.dust / 5; // 확산!
                cnt++; // 확산한 개수
            }
            vec[pos.y][pos.x] -= pos.dust / 5 * cnt; // 확산시킨만큼 현재위치의 먼지의 양을 줄여줌
        }
        vec[topAir.first - 1][0] = 0; // 공기청정기 바로 위
        // 각 방향으로 밀어주는 하드코딩
        for (int i = topAir.first - 2; i >= 0; --i)
        {
            vec[i+1][0] = vec[i][0];
        }
        for (int i = 0; i < c - 1; ++i)
        {
            vec[0][i] = vec[0][i + 1];
        }
        for (int i = 0; i < topAir.first; ++i)
        {
            vec[i][c - 1] = vec[i + 1][c - 1];
        }
        for (int i = c - 1; i > 1; --i)
        {
            vec[topAir.first][i] = vec[topAir.first][i - 1];
        } 
        vec[topAir.first][1] = 0; // 밀어줬으니 공기청정기 바로앞의 먼지는 제거
        vec[downAir.first + 1][0] = 0; // 공기청정기 바로 밑
        // 각 방향으로 밀어주는 하드코딩
        for (int i = downAir.first +2 ; i < r; ++i)
        {
            vec[i - 1][0] = vec[i][0];
        }
        for (int i = 0; i < c - 1; ++i)
        {
            vec[r-1][i] = vec[r-1][i + 1];
        }
        for (int i = r - 1; i > downAir.first; --i)
        {
            vec[i][c - 1] = vec[i - 1][c - 1];
        }
        for (int i = c - 1; i > 1; --i)
        {
            vec[downAir.first][i] = vec[downAir.first][i - 1];
        }
        vec[downAir.first][1] = 0; // 밀어줬으니 공기청정기 바로앞의 먼지는 제거

        // 공기청정기를 1초 돌린 후의 남은 먼지들을 체크해서 다시 큐에 넣어준다
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (vec[i][j] != -1 && vec[i][j] != 0)
                    q.push({ i,j,vec[i][j] });
            }
        }
        tempT++; // 1초
    }
}
int main()
{
    FASTIO;
    cin >> r >> c >> t;
    vec = vector<vector<int>>(r, vector<int>(c,0));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> vec[i][j];
            if (vec[i][j] < 0)
            {
                if (!bTop)  // 공기청정기는 위아래로 붙어있고, 
                            // 입력 특성상 공기청정기의 위쪽칸이 먼저 나올수밖에 없으니 불값을 하나 배정해줌
                {
                    topAir = { i,j };
                    bTop = true;
                }
                else downAir = { i,j };
            }
            else if (vec[i][j] != 0)
            {
                q.push({ i,j,vec[i][j] }); // 최초의 먼지를 넣기
            }
        }
    }
    func();
    int ans = 0;
    while (!q.empty()) // func에 의해 큐에는 남은 먼지들이 들어있다.
    {
        ans += q.front().dust;
        q.pop();
    }
    cout << ans;
    return 0;
}