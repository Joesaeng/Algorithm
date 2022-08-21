// BOJ 15988 :: 1,2,3 ¥ı«œ±‚ 3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000 + 1
#define MOD 10007
ll dp[MAX][10];
ll func(ll x)
{
	ll tmp = 0;
	for (int i = 2; i <= x; ++i)
	{
		for (int j = 0; j <= 9 ; ++j)
		{
			for (int k = j; k <= 9; ++k)
			{
				dp[i][j] += (dp[i - 1][k])%MOD;
			}
		}
	}
	for (int i = 0; i <= 9; ++i)
		tmp += (dp[x][i])%MOD;
	return tmp%MOD;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i <= 9; ++i)
		dp[1][i] = 1;

	cout << func(n);
	return 0;
}