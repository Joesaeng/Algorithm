// BOJ 1003 :: 피보나치 함수
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int dp0[41];
int dp1[41];
int cnt0, cnt1;
int fibonacciCnt0(int n) 
{
    int& ret = dp0[n];
    if (ret != -1) return ret;

    if (n == 0) {
        return ret = 1;
    }
    else if (n == 1) {
        return ret = 0;
    }
    else 
    {
        return ret = fibonacciCnt0(n-1) + fibonacciCnt0(n-2);
    }
}
int fibonacciCnt1(int n)
{
    int& ret = dp1[n];
    if (ret != -1) return ret;
    if (n == 0) {
        return ret = 0;
    }
    else if (n == 1) {
        return ret = 1;
    }
    else
    {
        return ret = fibonacciCnt1(n - 1) + fibonacciCnt1(n - 2);
    }
}


int main()
{
    FASTIO;
    memset(dp0, -1, sizeof(dp0));
    memset(dp1, -1, sizeof(dp1));
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n; cin >> n;
        cout << fibonacciCnt0(n) << ' ' << fibonacciCnt1(n) << '\n';
    }
    return 0;
}