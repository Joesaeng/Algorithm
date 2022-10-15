// BOJ 12851 :: 숨바꼭질 2
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k, t,cnt;
int vis[100001];
bool b;
void func()
{
    queue<pair<int,int>> q;
    int pos = n;
    int time = 0;
    q.push({ pos,time });
    vis[pos] = 0;
    while (!q.empty())
    {
        if (b) return; // 최소에 찾았으니 다음 탐색은 하지 않음
        int qsize = q.size();
        for (int i = 0; i < qsize; ++i)
        {
            pos = q.front().first;
            time = q.front().second;
            q.pop();
            if (pos == k)
            {
                cnt++;
                t = time;
                b = true; // 이번 시간에 찾았다 == 최소 시간
            }
            for (int j = 0; j < 3; ++j)
            {
                int x;
                if (j == 0) x = pos + 1;
                else if (j == 1) x = pos - 1;
                else if (j == 2) x = pos * 2;
                if (x < 0 || x > 100000) continue;
                if (vis[x] != -1 && vis[x] < time+1) continue; // 방문을 했고, 그 방문이 다음 방문보다 짧은 시간이라면 continue
                q.push({ x,time+1 });
                vis[x] = time+1;
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> n >> k;
    memset(vis, -1, sizeof(vis));
    func();
    cout << t << '\n' << cnt;
    return 0;
}