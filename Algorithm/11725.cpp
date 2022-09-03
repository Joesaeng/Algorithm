// BOJ 11725 :: 트리의 부모 찾기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define MAX 100001
int n, a, b;
vector<vector<int>> vec(MAX);
vector<int> parent(MAX);
void func(int cur)
{
	for (int i = 0; i < vec[cur].size(); ++i)
	{
		if (vec[cur][i] == parent[cur]) continue;
		parent[vec[cur][i]] = cur;
		func(vec[cur][i]);
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
	func(1);
	for (int i = 2; i <= n; ++i)
		cout << parent[i] << '\n';
	return 0;
}