// BOJ 1904 :: 01≈∏¿œ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define MOD 15746
int N;
vector<int> dp(1000001, -1);
int main()
{
	FASTIO;
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 1] % MOD + dp[i - 2] % MOD;
	}

    int res = dp[N] % MOD;
	cout << res;
	
	return 0;
}