// BOJ 2606 :: 바이러스
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<vector<int>> vec;
bool vis[1001];
int n,m,x,y, ans;
void DFS(int now)
{
    vis[now] = true;
    ans++;
    for (int i = 0; i < vec[now].size(); ++i)
    {
        int next = vec[now][i];
        if (vis[next]) continue;
        DFS(next);
    }
}
int main()
{
    FASTIO;
    cin >> n >> m;
    vec = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    DFS(1);
    cout << ans - 1;

    return 0;
}