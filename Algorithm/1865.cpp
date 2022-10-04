// BOJ 1865 :: ¿úÈ¦
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999999999
using namespace std;
int tc, s, e, t;
int n, m, w;
vector<pair<int, pair<int, int>>> vec;
vector<int> ans;
bool b;
void func(int start)
{
    ans[start] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < vec.size(); ++j)
        {
            int s = vec[j].first;
            int e = vec[j].second.first;
            int t = vec[j].second.second;
            if (ans[e] > ans[s] + t) ans[e] = ans[s] + t;
        }
    }
    for (int j = 0; j < vec.size(); ++j)
    {
        int s = vec[j].first;
        int e = vec[j].second.first;
        int t = vec[j].second.second;
        if (ans[e] > ans[s] + t)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
int main()
{
    FASTIO;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> w;
        vec.clear();
        ans = vector<int>(n + 1, INF);
        b = false;
        for (int i = 0; i < m; ++i)
        {
            cin >> s >> e >> t;
            vec.push_back(pair{ s,pair{e,t} });
            vec.push_back(pair{ e,pair{s,t} });
        }
        for (int i = 0; i < w; ++i)
        {
            cin >> s >> e >> t;
            vec.push_back(pair{ s,pair{e,-t} });
        }
        func(1);
    }
    return 0;
}