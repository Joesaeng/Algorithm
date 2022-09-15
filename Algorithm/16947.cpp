// BOJ 16947 :: 서울 지하철 2호선
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, a, b;
vector<vector<int>> vec;
vector<int> vis;
bool cycle;
int start;
void DFS(int pos,int prev)
{
	if (cycle) return;
	vis[pos] = 0;
	for (int i = 0; i < vec[pos].size(); ++i)
	{
		int next = vec[pos][i];
		if (next == prev) continue;
		if (next == start)
		{
			cycle = true;
			return;
		}
	}
	for (int i = 0; i < vec[pos].size(); ++i)
	{
		int next = vec[pos][i];
		if (next == prev) continue;
		if (vis[next] == 0) continue;
		DFS(next, pos);
	}
	if(!cycle)
		vis[pos] = -1;
}
void DFS2(int pos, int cnt)
{
	for (int i = 0; i < vec[pos].size(); ++i)
	{
		int next = vec[pos][i];
		if (vis[next] != -1) continue;
		if (vis[next] == 0) return;
		vis[next] = cnt;
		DFS2(next, cnt+1);
	}
}

int main()
{
	FASTIO;
	cin >> n;
	vec = vector<vector<int>>(n + 1);
	vis = vector<int>(n + 1,-1);
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i < vec.size(); ++i)
	{
		if (cycle) break;
		else vis = vector<int>(n + 1, -1);
		start = i;
		DFS(i,i);
	}
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vis[i] != 0) continue;
		DFS2(i,1);
	}
	for (int i = 1; i < vis.size(); ++i)
		cout << vis[i] << ' ';

	return 0;
}