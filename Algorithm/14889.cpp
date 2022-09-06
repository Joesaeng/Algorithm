// BOJ 14889 :: 스타트와 링크
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int vec[21][21];
vector<int> tmp1;
vector<int> tmp2;
bool vis[21];
int ans = INT32_MAX;
void DFS2(int idx,int cnt);
void DFS(int idx,int cnt)
{
	if (cnt == m)
	{
		DFS2(1,0);
		return;
	}
	for (int i = idx; i <= n; ++i)
	{
		if (vis[i]) continue;
		vis[i] = true;
		tmp1.push_back(i);
		DFS(i,cnt + 1);
		vis[i] = false;
		tmp1.pop_back();
	}
}
void DFS2(int idx,int cnt)
{
	if (cnt == m)
	{
		int t1 = 0;
		int t2 = 0;
		for(int i = 0;i < tmp1.size();++i)
			for (int j = i; j < tmp1.size(); ++j)
			{
				t1 += vec[tmp1[i]][tmp1[j]];
				t1 += vec[tmp1[j]][tmp1[i]];
			}
		for (int i = 0; i < tmp2.size(); ++i)
			for (int j = i; j < tmp2.size(); ++j)
			{
				t2 += vec[tmp2[i]][tmp2[j]];
				t2 += vec[tmp2[j]][tmp2[i]];
			}
		ans = min(ans, abs(t1 - t2));
		return;
	}
	for (int i = idx; i <= n; ++i)
	{
		if (vis[i]) continue;
		vis[i] = true;
		tmp2.push_back(i);
		DFS2(i,cnt + 1);
		vis[i] = false;
		tmp2.pop_back();
	}
}

void DFS3(int idx, int cnt)
{
	if (cnt == m)
	{
		int t1 = 0, t2 = 0;
		for(int i = 1;i <= n; ++i)
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
		return;
	}
	for (int i = idx; i <= n; ++i)
	{
		if (vis[i]) continue;
		vis[i] = true;
		DFS3(i, cnt + 1);
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
	DFS3(1,0);

	cout << ans;
	return 0;
}