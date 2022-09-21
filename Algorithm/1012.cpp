// BOJ 1012 :: ¿Ø±‚≥Û πË√ﬂ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, m, n, k;
int a, b, worms = 0;
vector<vector<int>> vec;
vector<vector<bool>> vis;
void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push(pair{ y,x });
    int diry[4] = { 0,0,-1,1 };
    int dirx[4] = { -1,1,0,0 };
    pair<int, int> now = pair{ y,x };
    vis[y][x] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nexty = now.first + diry[i];
            int nextx = now.second + dirx[i];
            if (nexty < 0 || nextx < 0 || nexty >= m || nextx >=n) continue;
            if (vis[nexty][nextx]) continue;
            if (vec[nexty][nextx] == -1 || vec[nexty][nextx] == 0) continue;
            q.push(pair{ nexty,nextx });
            vis[nexty][nextx] = true;
        }
    }
}
int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> m >> n >> k;
        vec = vector<vector<int>>(m, vector<int>(n, -1));
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int j = 0; j < k; ++j)
        {
            cin >> a >> b;
            vec[a][b] = 1;
        }
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (vis[y][x]) continue;
                if (vec[y][x] == -1 || vec[y][x] == 0) continue;
                BFS(y, x);
                worms++;
            }
        }
        cout << worms << '\n';
        worms = 0;
    }
    return 0;
}