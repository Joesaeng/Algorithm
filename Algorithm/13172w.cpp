// BOJ 13172 :: ¥Ò
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define MOD 1000000007
using ll = long long;
ll m, a, b, ans;
ll func(ll x, ll y)
{
    if (y == 1) return x;
    if (y % 2 == 1) return x * func(x, y - 1) % MOD;
    ll ret = func(x, y / 2);
    return ret * ret % MOD;
}
int main()
{
    FASTIO;
    cin >> m;
    while (m--)
    {
        cin >> b >> a;
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        ans += a * func(b, MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans % MOD;

    return 0;
}