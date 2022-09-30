// BOJ 17219 :: 비밀번호 찾기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
map<string, string> strmap;
string a, b;
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        strmap.emplace(a, b);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        cout << strmap[a] << '\n';
    }
    return 0;
}