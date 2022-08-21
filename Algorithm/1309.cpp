// BOJ 1309 :: µ¿¹°¿ø
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100000 + 1
#define MOD 9901
ll dp[MAX][3];
ll func(ll x)
{
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= x; ++i)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	return (dp[x][0] + dp[x][1] + dp[x][2]) % MOD;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	cout << func(n);
	return 0;
}