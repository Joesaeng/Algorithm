// BOJ 1912 :: ÇÕºÐÇØ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 201
#define	MOD 1000000000
ll dp[MAX][MAX];
ll func(ll n, ll k)
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	return dp[n][k] % MOD;
}



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n,k; cin >> n >> k;
	for (int i = 0; i <= k; ++i)
		dp[1][i] = i;
	cout << func(n,k);
	return 0;
}