// BOJ 14938 :: �����׶���
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, r;
int a, b, c;
int t[101];
int ans;
vector<vector<pair<int, int>>> vec;
vector<bool> vis;
int BFS(int begin)
{
    // ���� ��ġ�� ���� �ٸ� ��ΰ� ���� �� �ֱ� ������
    // �켱���� ť�� ����Ѵ�.(���ͽ�Ʈ�� �˰���)
    priority_queue<pair<int,int>> q;
    int pos = begin;
    int cost = 0;
    int ret = 0;
    q.push({ cost,pos });
    while (!q.empty())
    {
        cost = -q.top().first;
        pos = q.top().second;
        q.pop();
        if (vis[pos]) continue;
        vis[pos] = true;
        ret += t[pos];
        for (int i = 0; i < vec[pos].size(); ++i)
        {
            int next = vec[pos][i].second;
            int ncost = vec[pos][i].first + cost;
            if (ncost > m) continue;
            if (vis[next]) continue;
            q.push({ -ncost,next });
        }
    }
    return ret;
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
        vec[a].push_back({ c,b }); // ����� ����
        vec[b].push_back({ c,a }); 
    }
    for (int i = 1; i <= n; ++i)
    {
        vis = vector<bool>(n + 1,false);
        ans = max(ans, BFS(i));
    }
    cout << ans;
    return 0;
}