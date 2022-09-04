// BOJ 1967 :: 트리의 지름
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 10001
using namespace std;
int  n, a, b, c;
vector<pair<int, int>> vec[MAX];
bool vi[MAX];
int far = 0;
int ans = 0;
void DFS(int vt,int cost)
{
	if (cost > ans)
	{
		ans = cost;
		far = vt;
	}
	vi[vt] = true;
	for (int i = 0; i < vec[vt].size(); ++i)
	{
		int next = vec[vt][i].first;
		if (vi[next])continue;
		DFS(next, cost + vec[vt][i].second);
	}
	vi[vt] = false;
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	DFS(1, 0);
	DFS(far, 0);
	cout << ans;
	return 0;
}