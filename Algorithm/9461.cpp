// BOJ 9461 :: 파도반 수열
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int t, n;
ll dp[101];
int main()
{
	FASTIO;
	cin >> t;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int j = 0; j < t; ++j)
	{
		cin >> n;
		if (n <= 5)
		{
			cout << dp[n] << '\n';
			continue;
		}
		for (int i = 6; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n] << '\n';
	}

	return 0;
}