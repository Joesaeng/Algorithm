// BOJ 1057 :: 토너먼트
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, a, b,cnt = 1;
void func()
{
    while (n)
    {
        if ((a + 1) / 2 == (b + 1) / 2)
        {
            cout << cnt;
            return;
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        cnt++;
        n /= 2;
    }
    cout << "-1";
}
int main()
{
    FASTIO;
    cin >> n >> a >> b;
    func();
    return 0;
}