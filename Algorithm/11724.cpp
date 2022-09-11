// BOJ 11724 :: 연결 요소의 개수
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int ans = 0;
bool vis[1001];
vector<vector<int>> vec;
void DFS(int num)
{
	vis[num] = true;
	for (int i = 0; i < vec[num].size(); ++i)
	{
		int next = vec[num][i];
		if (vis[next]) continue;
		DFS(vec[num][i]);
	}
}
int main()
{
	FASTIO;
	cin >> n >> m;
	vec.resize(n + 1);
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vis[i]) continue;
		DFS(i);
		ans++;
	}
	cout << ans;
	return 0;
}