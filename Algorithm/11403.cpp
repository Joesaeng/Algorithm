// BOJ 11403 :: 경로 찾기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
vector<vector<int>> vec;
vector<vector<int>> ans;
bool vis[100];
void DFS(int start, int now)
{
    for (int i = 0; i < n; ++i)
    {
        if (vec[now][i] == 1 && !vis[i])
        {
            vis[i] = true;
            DFS(start, i);
            ans[start][i] = 1;
        }
    }
}
int main()
{
    FASTIO;
    cin >> n;
    vec = vector<vector<int>>(n, vector<int>(n));
    ans = vector<vector<int>>(n, vector<int>(n,0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> vec[i][j];
    }
    for (int i = 0; i < n; ++i)
    {
        memset(vis, false, sizeof(vis));
        DFS(i,i);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}