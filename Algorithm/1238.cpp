// BOJ 1238 :: 파티
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 987654321
int n,m,x,a,b,c;
vector<vector<pair<int,int>>> road;
vector<int> ans;
int res;
int func(int start,int dest)
{
    int pos = start;
    vector<int> dist = vector<int>(n + 1,INF);
    priority_queue<pair<int,int>> q;
    dist[pos] = 0;
    q.push(pair{0,pos});

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
    return 987654321;
}
int main()
{
    FASTIO;
    cin >> n >> m >> x;
    road = vector<vector<pair<int,int>>>(n + 1);
    ans = vector<int>(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        road[a].push_back(pair{ c,b });//a에서 b로 가는데 c의 시간이 걸림
    }
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = func(i, x); // i번째 학생이 파티하는 x까지 가는데 걸리는 시간
    }
    for (int i = 1; i <= n; ++i)
    {
        ans[i] += func(x, i); // i번째 학생이 파티하는 x에서 집으로 돌아가는데 걸리는 시간
        res = max(res, ans[i]);
    }
    cout << res;
    return 0;
}