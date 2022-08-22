// BOJ 1932 :: Á¤¼ö »ï°¢Çü
#include <bits/stdc++.h>
using namespace std;
#define MAX 500 + 1
int v[MAX][MAX];
int dp[MAX][MAX];
int func(int x)
{
	dp[1][1] = v[1][1];

	int tmp = 0;
	for (int i = 2; i <= x; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = max(dp[i - 1][j] + v[i][j],dp[i-1][j-1] + v[i][j]);
		}
	}
	for (int i = 1; i <= x; ++i)
	{
		tmp = max(tmp, dp[x][i]);
	}
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
			cin >> v[i][j];
	}
	cout << func(n);


	return 0;
}