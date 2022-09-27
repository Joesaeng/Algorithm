// BOJ 16928 :: 뱀과 사다리 게임
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int a, b;
vector<vector<int>> vec(101);
bool vis[101];
int BFS()
{
    queue<pair<int,int>> q;
    int pos = 1;
    int cnt = 0;
    vis[pos] = true;
    q.push(pair{ pos,cnt });
    while (!q.empty())
    {
        pos = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (pos == 100)
        {
            return cnt;
        }
        for (int i = 1; i <= 6; ++i)
        {
            int next = pos + i;
            if (next > 100) break;
            if (vis[next]) continue;
            vis[next] = true;
            if (vec[next].size() < 1)
            {
                q.push(pair{ next,cnt + 1 });
            }
            else
            {
                q.push(pair{ vec[next][0],cnt + 1 });
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        vec[a].push_back(b);
    }
    cout << BFS();


    return 0;
}