// BOJ 1260 :: DFS¿Í BFS
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<vector<int>> vec(1001);
vector<int> dfs;
int n, m, v, a, b;
bool vis[1001];
void DFS(int cur)
{
	vis[cur] = true;
	cout << cur << ' ';
	for (int i = 0;i < vec[cur].size(); ++i)
	{
		int next = vec[cur][i];
		if (vis[next]) continue;
		DFS(next);
	}
}
void BFS()
{
	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); ++i)
		{
			int next = vec[x][i];
			if (vis[next]) continue;
			q.push(next);
			vis[next] = true;
		}
		cout << x << ' ';
	}

}

int main()
{
	FASTIO;
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		sort(vec[i].begin(), vec[i].end());
	DFS(v);
	cout << '\n';
	memset(vis, false, sizeof(vis));
	BFS();

	return 0;
}