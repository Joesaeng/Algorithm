// BOJ 1389 :: 케빈 베이컨의 6단계 법칙
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int a, b;
vector<vector<int>> vec;
vector<bool> vis;
int x = 55555;
int dp[101][101];
void DFS(int me,int now,int frnd,int depth)
{
    if (dp[now][frnd] != -1)
    {
        x = min(x, dp[now][frnd] + depth);
        return;
    }
    if (now == frnd)
    {
        x = min(x, depth);
        dp[me][frnd] = min(dp[me][frnd], depth);
        dp[frnd][me] = dp[me][frnd];
        return;
    }
    vis[now] = true;
    for (int i = 0; i < vec[now].size(); ++i)
    {
        if (vis[vec[now][i]]) continue;
        DFS(me,vec[now][i], frnd, depth + 1);
    }
    vis[now] = false;
}
int main()
{
    FASTIO;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vec = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    int res = INT32_MAX;
    int man = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            if (dp[i][j] != -1) tmp += dp[i][j];
            else
            {
                vis.resize(n + 1);
                vis[i] = true;
                DFS(i,i,j,0);
                tmp += x;
                x = 55555;
            }
        }
        if (res > tmp)
        {
            res = tmp;
            man = i;
        }
    }
    cout << man;
    return 0;
}