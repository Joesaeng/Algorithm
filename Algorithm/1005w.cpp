// BOJ 1005 :: ACM Craft
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t;
int n, k, w;
vector<int> delay;          // i번째 건물만 짓는데 걸리는 시간
vector<vector<int>> road;   // 건물을 짓는 규칙
vector<int> resT;           // i번째 건물을 짓는데 걸리는 시간
vector<int> entry;          // i번째 건물을 짓는데 필요한 건물 개수
int func(int dest)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (entry[i] == 0) // i번째 건물을 짓는데 필요한 건물이 없을 때
        {
            q.push(i); // 큐에 넣어주고
            resT[i] = delay[i]; // i번째 건물을 짓는데 걸리는 시간
        }
    }
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        for (int i = 0; i < road[pos].size(); ++i)
        {
            int next = road[pos][i];
            // 다음 건물을 짓기 위해 필요한 시간은 다음 건물을 짓기위해 필요한
            // 건물중 가장 오래걸리는 건물이 지어지는데 걸리는 시간이기 때문에
            // 최대값으로 갱신해준다.
            resT[next] = max(resT[next], resT[pos] + delay[next]); 
            entry[next]--; // 다음 건물을 짓는데 필요한 건물의 수를 감한다.
            if (entry[next] == 0) q.push(next); // 다음 건물을 지을 수 있다면 큐에 넣어준다.
        }
    }
    return resT[dest];
}
int main()
{
    FASTIO;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        delay = vector<int>(n + 1);
        road = vector<vector<int>>(n + 1);
        resT = vector<int>(n + 1);
        entry = vector<int>(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> delay[i];
        }
        for (int i = 0; i < k; ++i)
        {
            int a, b;
            cin >> a >> b;
            road[a].push_back(b);
            entry[b]++;
        }
        cin >> w;
        cout << func(w) << '\n';
    }
    return 0;
}