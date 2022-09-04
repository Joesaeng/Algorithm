// BOJ 16964 :: DFS 스페셜 저지
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100001
using namespace std;
int n, a, b;
vector<int> vec[MAX];
int ans[MAX];
int order[MAX];
bool vis[MAX];
int cnt = 1;
bool comp(const int& a, const int& b)
{
	return order[a] < order[b];
}
void DFS(int cur)
{
	if (ans[cnt] != cur) return;
	cnt++;
	if (vis[cur]) return;
	vis[cur] = true;
	for (int next : vec[cur])
	{
		if (vis[next]) continue;
		DFS(next);
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		ans[i] = a;
		order[a] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(vec[i].begin(), vec[i].end(), comp);
	}
	DFS(1);
	if (cnt == n + 1) cout << 1;
	else cout << 0;

	return 0;
}