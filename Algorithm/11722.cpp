// BOJ 11722 :: 가장 긴 감소하는 부분 수열
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 + 1
int v[MAX];
int dp[MAX];
int func(int x)
{
	int tmp = 0;
	for (int i = 1; i <= x; ++i)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; --j)
		{
			if (v[i] < v[j])
			{
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}
		tmp = dp[i] > tmp ? dp[i] : tmp;
	}


	return tmp;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	cout << func(n);
	return 0;
}