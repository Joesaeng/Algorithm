// BOJ 1504 :: 특정한 최단 경로
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n, e, a, b, c, v1, v2;
vector<vector<pair<int, int>>> road;
int func(int start, int dest)
{
    int pos = start;
    vector<int> dist = vector<int>(n + 1, INF);
    priority_queue<pair<int, int>> q;
    dist[pos] = 0;
    q.push(pair{ 0,pos });

    while (!q.empty())
    {
        int cost = -q.top().first;
        pos = q.top().second;
        q.pop();

        if (pos == dest) return cost;

        for (int i = 0; i < road[pos].size(); ++i)
        {
            int next = road[pos][i].second;
            int nCost = road[pos][i].first;
            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                q.push(pair{ -dist[next], next });
            }
        }
    }
    return -1;
}
int main()
{
    FASTIO;
    cin >> n >> e;
    int ans = -1;
    road = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        road[a].push_back(pair{ c,b });
        road[b].push_back(pair{ c,a });
    }
    cin >> v1 >> v2;
    {
        int x = func(1, v1); int y = func(v1, v2); int z = func(v2, n); // 1 -> v1 -> v2 -> n의 최단경로
        if (x == -1 || y == -1 || z == -1) ans = -1; // 하나라도 끊어져 있다면
        else ans = x + y + z;
    }
    {
        int x = func(1, v2); int y = func(v2, v1); int z = func(v1, n); // 1 -> v2 -> v1 -> n의 최단경로
        if ((x == -1 || y == -1 || z == -1) && ans == -1) ans = -1; // 길이 하나라도 끊어져 있고, 위에서도 끊어져 있었다면
        else if (ans == -1) ans = x + y + z; // 이번 길은 끊어져 있지 않은데, 위에서는 끊어져 있었다면
        else
            ans = min(ans, x + y + z); // 두 길 다 끊어져있지 않았다면
    }
    cout << ans;
    return 0;
}