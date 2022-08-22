// BOJ 2156 :: 포도주 시식
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000 + 1
int v[MAX];
int dp[MAX];
int func(int x)
{
	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for (int i = 3; i <= x; ++i)
	{
		dp[i] = max(dp[i - 2] + v[i], max(dp[i - 1],dp[i-3]+v[i]+v[i-1]));
	}
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	cout << func(n);


	return 0;
}