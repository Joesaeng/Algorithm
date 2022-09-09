// BOJ 1182 :: 부분수열의 합
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int v[20];
int ans[20];
int n, s;
int c;
bool vis[20];
void DFS(int idx,int cnt)
{
	if (cnt >= 1)
	{
		int res = 0;
		for (int i = 0; i < cnt; ++i)
		{
			res += ans[i];
			cout << ans[i] << ' ';
		}
		cout << " = " << res << '\n';
		if (res == s) c++;
		if (cnt >= n + 1) return;
	}
	for (int i = idx; i < n; ++i)
	{
		if (vis[i]) continue;
		vis[i] = true;
		ans[cnt] = v[i];
		DFS(i, cnt + 1);
		ans[cnt] = 0;
		vis[i] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	DFS(0, 0);
	cout << c;

	return 0;
}