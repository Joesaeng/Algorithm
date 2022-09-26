// BOJ 1541 :: ภาพ๎น๖ธฐ ฐýศฃ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string st;
string num;
int ans;
bool b;
int main()
{
    FASTIO;
    cin >> st;
    for (int i = 0; i < st.length(); ++i)
    {
        if (st[i] == '+' || st[i] == '-' || i == st.length() - 1)
        {
            if (i == st.length() - 1)
                num += st[i];
            if (b) ans -= stoi(num);
            else ans += stoi(num);
            if (st[i] == '-') b = true;
            num = "";
        }
        else
            num += st[i];
    }
    cout << ans;
    return 0;
}