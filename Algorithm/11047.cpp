// BOJ 11047 :: µ¿Àü 0
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n,k,ans;
int coin[10];
int main()
{
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    for (int i = n - 1; i >= 0; --i)
    {
        if (k >= coin[i] && k > 0)
        {
            ans += k / coin[i];
            k = k % coin[i];
        }
        if (k == 0)
            break;
    }
    cout << ans;
    return 0;
}