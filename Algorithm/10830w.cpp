// BOJ 10830 :: 행렬 제곱
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000
using ll = long long;
using namespace std;
int n;
ll b;
// 행렬의 곱셉을 구현하고, 분할정복으로 풀어야 하는 문제.
struct matrix
{
    matrix()
    {
    }
    matrix(int a)
    {
        vec = vector<vector<ll>>(a, vector<ll>(a));
    }
    matrix operator *(const matrix& other)
    {
        matrix tmp(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                {
                    tmp.vec[i][j] += vec[i][k] * other.vec[k][j];
                    tmp.vec[i][j] % MOD;
                }
        return tmp%MOD;
    }
    matrix operator %(const int x)
    {
        matrix tmp;
        tmp.vec = vec;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tmp.vec[i][j] %= x;
        return tmp;
    }
    vector<vector<ll>> vec;
};
matrix mat;
matrix ans;
matrix MUL(ll x)
{
    if (x == 1) return mat%MOD;
    matrix ret = MUL(x / 2);
    if (x % 2 == 0) return (ret * ret)%MOD;
    else return (((ret * ret)%MOD) * mat)%MOD;
}
int main()
{
    FASTIO;
    cin >> n >> b;
    mat = matrix(n);
    ans = matrix(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat.vec[i][j];
        }
    }
    ans = MUL(b);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans.vec[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}