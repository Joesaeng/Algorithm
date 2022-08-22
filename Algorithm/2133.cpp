// BOJ 2133 :: 타일 채우기
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 30 + 1
int dp[MAX];
int func(int x)
{
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	if (x % 2 != 0)
		return 0;
	for (int i = 4; i <= x; i+=2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	cout << func(n);
	return 0;
}