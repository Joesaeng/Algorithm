// BOJ 1167 :: 트리의 지름
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, a, b, c;
vector<pair<int, int>> vec[100001];
bool vi[100001];
int ans = 0;
int far = 0;
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
		if (vi[next]) continue;
		DFS(next,cost + vec[vt][i].second);
	}
	vi[vt] = false;
}
void input(int num)
{
	cin >> b;
	if (b == -1) return;
	cin >> c;
	vec[num].push_back({ b,c });
	input(num);
}
int main()
{
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		input(a);
	}
	DFS(1,0);
	DFS(far, 0);

	cout << ans;
	return 0;
}