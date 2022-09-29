// BOJ 5525 :: IOIOI
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, s;
string m;
int ans;
int main()
{
    FASTIO;
    cin >> n >> s >> m;
    for (int i = 0; i < s; ++i)
    {
        int cnt = 0;
        if(m[i] == 'I')
            while (m[i + 1] == 'O' && m[i + 2] == 'I')
            {
                i += 2;
                cnt++;
                if (cnt == n)
                {
                    cnt--;
                    ans++;
                }
            }
    }
    cout << ans;
    return 0;
}