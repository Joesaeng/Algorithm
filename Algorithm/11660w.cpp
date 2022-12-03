// BOJ 11660 :: 구간 합 구하기 5
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int a, aa, b, bb;
int vec[1025][1025]; // 입력값을 받는 배열
//  [1,1][1,2][1,3][1,4][1,5]
//  [2,1][2,2][2,3][2,4][2,5]
//  [3,1][3,2][3,3][3,4][3,5]  >>> dp[3][3] 의 값은
//  [4,1][4,2][4,3][4,4][4,5]      vec[1][1] ~ vec[1][3] + vec[2][1] ~ vec[2][3] +
//  [5,1][5,2][5,3][5,4][5,5]      vec[3][1] ~ vec[3][3] 로 저장해둔다
int dp[1025][1025]; // dp[x][y] 
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
        for (int j = 1; j <= n; ++j) // 배열값을 입력받고 dp를 채워주는 반복문
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