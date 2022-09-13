// BOJ 2579 :: 계단 오르기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
vector<int> dp;
int n;
vector<int> vec;

int main()
{
	FASTIO;
	cin >> n;
	vec = vector<int>(n + 1);
	dp = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> vec[i];
	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = vec[i] + max(vec[i-1] + dp[i-3], dp[i - 2]);
	}
	int res = dp[n];
	cout << res;
	return 0;
}