// BOJ 13015 :: 별 찍기 23
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
void centerH(int x, int s)
{
    if (x == 1) return;
    for (int i = n; i >= x; --i)
        cout << ' ';
    cout << '*';
    for (int i = 1; i <= s; ++i)
        cout << ' ';
    if(x != 2)
        cout << '*';
    for (int i = 1; i <= (x - 2) * 2 - 1; ++i)
        cout << ' ';
    cout << '*';
    for (int i = 1; i <= s; ++i)
        cout << ' ';
    cout << '*';
    cout << '\n';
    centerH(x - 1, s);
}
void centerL(int x, int s)
{
    if (x == n) return;
    for (int i = x; i < n; ++i)
        cout << ' ';
    cout << '*';
    for (int i = 1; i <= s; ++i)
        cout << ' ';
    cout << '*';
    for (int i = 1; i<= (x - 1) * 2 - 1; ++i)
        cout << ' ';
    cout << '*';
    for (int i = 1; i <= s; ++i)
        cout << ' ';
    cout << '*';
    cout << '\n';
    centerL(x + 1, s);
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cout << '*';
    for (int i = 1; i <= (n - 1) * 2 - 1; ++i)
        cout << ' ';
    for (int i = 1; i <= n; ++i)
        cout << '*';                // 첫번째 줄
    cout << '\n';
    centerH(n, n - 2);              // 두번째 ~ 가운데
    centerL(2, n - 2);              // 가운데 +1 ~ 마지막 -1
    for (int i = 1; i <= n; ++i)
        cout << '*';
    for (int i = 1; i <= (n - 1) * 2 - 1; ++i)
        cout << ' ';
    for (int i = 1; i <= n; ++i)
        cout << '*';                // 마지막 줄
    return 0;
}