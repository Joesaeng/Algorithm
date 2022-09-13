// BOJ 12865 :: Æò¹üÇÑ ¹è³¶
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k, a, b;
vector<pair<int, int>> vec;
vector<vector<int>> dp;
int main()
{
	FASTIO;
	cin >> n >> k;
	vec = vector<pair<int, int>>(n + 1);
	dp = vector<vector<int>>(n+1,vector<int>(k+1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b;
		vec[i].first = a;
		vec[i].second = b;
	}
	dp[0][0] = 0;
	int res = 0;
	for (int w = 1; w <= k; ++w)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (vec[i].first <= w)
			{
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - vec[i].first] + vec[i].second);
			}
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	cout << dp[n][k];

	return 0;
}