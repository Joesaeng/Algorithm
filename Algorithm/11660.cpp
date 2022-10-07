// BOJ 11660 :: 구간 합 구하기 5
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int a, aa, b, bb;
int vec[1025][1025];
int dp[1025][1025];
int func(int a, int aa, int b, int bb) // (a,aa) 부터 (b,bb) 까지의 합
{
    return dp[b][bb] - dp[a-1][bb] - dp[b][aa-1] + dp[a-1][aa-1];
}
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> vec[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + vec[i][j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> aa >> b >> bb;
        cout << func(a, aa, b, bb) << '\n';
    }
    return 0;
}