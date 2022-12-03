// BOJ 11444 :: 피보나치 수 6
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
#define MOD 1000000007
#define matrix vector<vector<ll>>
ll n;
matrix vec;
// 피보나치의 점화식을 행렬 곱셈을 통해 구한다.
// | F(n+1) F(n)   |  == | 1  1 |^n
// | F(n)   F(n-1) |  == | 1  0 |
matrix operator*(matrix& left, matrix& right)
{
    matrix temp(2, vector<ll>(2));
    for(int i = 0;i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                temp[i][j] += left[i][k] * right[k][j];
            }
            temp[i][j] %= MOD;
        }
    return temp;
}
int main()
{
    FASTIO;
    cin >> n;
    matrix ans = { {1,0},{0,1} };
    matrix x = { {1,1},{1,0} };
    while (n > 0)
    {
        if (n % 2 == 1) ans = ans * x;
        x = x * x;
        n /= 2;
    }
    cout << ans[0][1];
    return 0;
}