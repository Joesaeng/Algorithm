// BOJ 1699 :: 제곱수의 합
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100001
ll dp[MAX];

ll func(int x)
{
	for (int i = 1; i <= x; ++i)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = dp[i] < dp[i - j * j] + 1 ? dp[i] : dp[i - j * j] + 1;
		}
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