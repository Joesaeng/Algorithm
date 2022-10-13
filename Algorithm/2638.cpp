// BOJ 2638 :: 치즈
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, cheez = 0;
int ans;
int vec[100][100];
bool vis[100][100];
queue<pair<int, int>> outQ;
queue<pair<int, int>> cq;
void outside()
{
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };
    while (!outQ.empty()) // 외부 탐색
    {
        int y = outQ.front().first;
        int x = outQ.front().second;
        outQ.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (vis[ny][nx]) continue;
            vis[ny][nx] = true; // 외부 공기이거나, 이번 탐색에서 찾은 아이들
            if (vec[ny][nx] == 1) cq.push({ ny,nx }); // 치즈라면 치즈큐(cq)에 넣는다
            else outQ.push({ ny,nx });
        }
    }
    while (!cq.empty()) // 치즈 탐색
    {
        int y = cq.front().first;
        int x = cq.front().second;
        int cnt = 0; // 외부 공기와 맞닿은 변의 수
        cq.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (vis[ny][nx] == true && vec[ny][nx] == 0) cnt++; // 외부공기
        }
        if (cnt >= 2)
        {
            outQ.push({ y,x }); // 녹인 치즈들은 외부 공기가 된다.
            cheez--;            // 메인함수에서의 반복문을 위한 치즈 개수 제거
        }
        else vis[y][x] = false; // 녹지 않았다면 다음을 위해 방문을 취소한다
    }
    int qsize = outQ.size();
    for (int i = 0; i < qsize; ++i) // 이번에 녹을 치즈들을 녹이는 과정, 찾자마자 녹이게 되면 이번 턴에서 녹지 않아야 할 치즈들이 녹게된다.
    {
        int y = outQ.front().first;
        int x = outQ.front().second;
        outQ.pop();
        vec[y][x] = 0;
        outQ.push({ y,x });
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 1) cheez++;
        }
    }
    outQ.push({ 0,0 });
    outQ.push({ 0,m-1 });
    outQ.push({ n-1,0 });
    outQ.push({ n-1,m-1 });
    vis[0][0] = vis[0][m - 1] = vis[n - 1][0] = vis[n - 1][m - 1] = true; // 각 모서리에서 탐색을 시작한다 : 0,0에서 시작해도 무방함
    while (cheez > 0)
    {
        outside();
        ans++;
    }
   
    cout << ans;
    return 0;
}

// 가장자리에 있는 치즈들을 찾는다.
// 그 중에 녹을 치즈들(외부공기와 2변이상이 맞닿아있는)을 찾는다.
// 녹을 치즈들을 녹이고, 이걸 반복?