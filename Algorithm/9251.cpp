// BOJ 9251 :: LCS
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string s1, s2;
int dp[1001][1001];
int main()
{
	FASTIO;
	string t1, t2;
	cin >> t1 >> t2;
	s1 = '0' + t1;
	s2 = '0' + t2;

	int l1 = s1.size();
	int l2 = s2.size();
	for(int i = 0; i < l1; ++i)
		for (int j = 0; j < l2; ++j)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (s1[i] == s2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

	cout << dp[l1 - 1][l2 - 1];


	return 0;
}