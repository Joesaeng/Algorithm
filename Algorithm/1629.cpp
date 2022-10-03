// BOJ 1629 :: °ö¼À
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int a, b, c;
ll func(int n)
{
    if (n == 1) return a % c;
    ll ret = func(n / 2);
    if (n % 2 == 0) return (ret * ret) % c;
    else return (((ret * ret) % c) * a) % c;
}
int main()
{
    FASTIO;
    cin >> a >> b >> c;
    cout << func(b);
    return 0;
}