// BOJ 14501 :: Επ»η
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
vector<pair<int, int>> vec(16);
bool vis[16];
int ans = 0;
void DFS(int day,int pay)
{
	if (day > n+1) return;
	ans = max(ans, pay);
	for (int i = day; i <= n; ++i)
	{
		if (vis[i]) continue;
		vis[day] = true;
		DFS(day + vec[i].first + (i - day), pay + vec[i].second);
		vis[day] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	DFS(1, 0);
	cout << ans;
	return 0;
}