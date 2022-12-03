// BOJ 14502 :: 연구소
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, ans;
vector<vector<int>> vec; // 맵
vector<pair<int,int>> s; // 벽을 세울 위치
vector<pair<int, int>> v; // 바이러스 위치
bool vis[65];
// 3개의 벽을 세우는 경우의 수를 DFS로 찾고
// BFS를 통해 안전영역의 크기를 알아낸다.
int BFS(vector<vector<int>> vc) // 맵을 바꾸면서 찾기 때문에 복사해서 받는다.
{
	int ret = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); ++i)
	{
		q.push({ v[i].first,v[i].second }); // 바이러스의 위치를 넣어줌
	}
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };

	// 바이러스를 퍼트리는 BFS
	while (!q.empty()) 
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
			if (vc[nexty][nextx] != 0) continue;
			vc[nexty][nextx] = 2;
			q.push({ nexty,nextx });
		}
	}

	// 바이러스를 퍼트린 후에 맵을 순회하며 안전영역의 개수를 찾음
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j)
		{
			if (vc[i][j] == 0) ret++;
		}
	}
	return ret;
}
void DFS(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			vec[s[i].first][s[i].second] = 1;
		}
		ans = max(ans,BFS(vec));
		for (int i = 0; i < 3; ++i)
		{
			vec[s[i].first][s[i].second] = 0;
		}
		return;
	}
	for (int i = idx; i <= n*m; ++i)
	{
		if (vis[i]) continue;
		int nexty = (i - 1) / m;
		int nextx = (i - 1) % m;
		if (vec[nexty][nextx] != 0) continue;
		vis[i] = true;
		s.push_back({ nexty,nextx });
		DFS(i, cnt + 1);
		vis[i] = false;
		s.pop_back();
	}
}
int main()
{
    FASTIO;
    cin >> n >> m;
	vec = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
			if (vec[i][j] == 2)
				v.push_back({ i,j });
        }
    }
	DFS(1, 0);
	cout << ans;
    return 0;
}