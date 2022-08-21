// BOJ 1149 :: RGB °Å¸®
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
enum
{
	R = 0,
	G = 1,
	B = 2,
};
#define MAX 1001
ll v[MAX][3];
ll dp[MAX][3];

ll func(int x)
{
	dp[0][R] = dp[0][G] = dp[0][B] = 0;
	for (int i = 1; i <= x; ++i)
	{
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + v[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + v[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + v[i][B];
	}
	return min(dp[x][2],min(dp[x][0],dp[x][1]));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i][R] >> v[i][G] >> v[i][B];
	}
	cout << func(n);
	return 0;
}