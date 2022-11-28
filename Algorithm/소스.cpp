// BOJ 0 ::
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int main()
{
    FASTIO;
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll ans = 1;
        ll tmp = 1;
        for (int i = m; i > m - n; i--)
        {
            ans *= i;
            ans /= tmp++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}