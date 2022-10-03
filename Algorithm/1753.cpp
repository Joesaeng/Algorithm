// BOJ 1753 :: 최단 경로
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int v, e, start;
int a, b, c;
vector<vector<pair<int,int>>> vec;
vector<int> ans;
void func()
{
    priority_queue<pair<int,int>> q;
    int pos = start;
    ans[pos] = 0;
    q.push(pair{0,pos});
    int x = 0;
    while (!q.empty())
    {
        x = -q.top().first;
        pos = q.top().second;
        q.pop();
        for (int i = 0; i < vec[pos].size(); ++i)
        {
            int nextpos = vec[pos][i].first;
            int tmp = x + vec[pos][i].second;
            if (ans[nextpos] > tmp)
            {
                ans[nextpos] = tmp;
                q.push(pair{ -ans[nextpos],nextpos });
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> v >> e >> start;
    vec = vector<vector<pair<int, int>>>(v + 1);
    ans = vector<int>(v + 1, INT32_MAX);
    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        vec[a].push_back(pair{ b,c });
    }
    func();
    for (int i = 1; i <= v; ++i)
    {
        if (ans[i] == INT32_MAX) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
    return 0;
}