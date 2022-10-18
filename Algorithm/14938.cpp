// BOJ 14938 :: 서강그라운드
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, r;
int a, b, c;
int t[101];
int ans;
int tmp;
vector<vector<pair<int, int>>> vec;
vector<bool> vis;
void BFS(int begin)
{
    priority_queue<pair<int,int>> q;
    int pos = begin;
    int cost = 0;
    q.push({ cost,pos });
    while (!q.empty())
    {
        cost = -q.top().first;
        pos = q.top().second;
        q.pop();
        if (vis[pos]) continue;
        vis[pos] = true;
        tmp += t[pos];
        for (int i = 0; i < vec[pos].size(); ++i)
        {
            int next = vec[pos][i].second;
            int ncost = vec[pos][i].first + cost;
            if (ncost > m) continue;
            if (vis[next]) continue;
            q.push({ -ncost,next });
        }
    }
}
int main()
{
    FASTIO;
    cin >> n >> m >> r;
    vec = vector<vector<pair<int, int>>>(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 0; i < r; ++i)
    {
        cin >> a >> b >> c;
        vec[a].push_back({ c,b });
        vec[b].push_back({ c,a });
    }
    for (int i = 1; i <= n; ++i)
    {
        vis = vector<bool>(n + 1,false);
        tmp = 0;
        BFS(i);
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}