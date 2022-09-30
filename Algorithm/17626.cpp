// BOJ 17626 :: Four Squares
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int dp[50001];
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 1; i*i <= n; ++i)
        dp[i * i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] != 0) continue;
        for (int j = 1; j * j <= i; ++j)
        {
            if (dp[i] == 0) dp[i] = dp[j * j] + dp[i - j * j];
            else dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }
    cout << dp[n];

    return 0;
}