// BOJ 11659 :: 구간 합 구하기 4
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, a, b;
int dp[100001];
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        dp[i] = dp[i - 1] + a;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
    return 0;
}