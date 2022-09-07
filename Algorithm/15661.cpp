// BOJ 15661 :: 링크와 스타트
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int vec[21][21];
bool vis[21];
int ans = INT32_MAX;
void DFS(int idx, int cnt)
{
	if (cnt >= 2 && cnt <= m)
	{
		int t1 = 0, t2 = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (vis[i] && vis[j])
				{
					t1 += vec[i][j];
				}
				if (!vis[i] && !vis[j])
				{
					t2 += vec[i][j];
				}
			}
		ans = min(ans, abs(t1 - t2));
		if (cnt == m)
			return;
	}
	for (int i = idx; i <= n; ++i)
	{
		if (vis[i]) continue;
		vis[i] = true;
		DFS(i, cnt + 1);
		vis[i] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> vec[i][j];
	}
	m = n / 2;
	DFS(1, 0);

	cout << ans;
	return 0;
}