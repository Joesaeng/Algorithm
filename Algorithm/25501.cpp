// BOJ 25501 :: ¿Á±Õ¿« ±Õ¿Á
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, cnt = 0;
char s[1001];
int recursion(const char* s, int l, int r)
{
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    FASTIO
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        cout << isPalindrome(s) << ' ' << cnt << '\n';
        cnt = 0;
    }
}