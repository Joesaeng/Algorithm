// BOJ 9465 :: ½ºÆ¼Ä¿
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1
int v[2][MAX];
int dp[2][MAX];
int func(int x)
{
	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = v[0][1];
	dp[1][1] = v[1][1];
	for (int i = 2; i <= x; ++i)
	{
		dp[0][i] = max(dp[1][i - 1] + v[0][i], max(dp[0][i - 2] + v[0][i], dp[1][i - 2]+v[0][i]));
		dp[1][i] = max(dp[0][i - 1] + v[1][i], max(dp[0][i - 2] + v[1][i], dp[1][i - 2]+v[1][i]));
	}
	return max(dp[0][x], dp[1][x]);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		for (int j = 1; j <= a; ++j)
		{
			cin >> v[0][j];
		}
		for (int j = 1; j <= a; ++j)
		{
			cin >> v[1][j];
		}
		cout << func(a) << '\n';
	}

	


	return 0;
}