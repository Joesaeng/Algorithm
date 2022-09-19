// BOJ 11399 :: ATM
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<int> vec;
int main()
{
    FASTIO;
    int n;
    int ans = 0;
    cin >> n;
    vec = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int tmp = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        tmp += vec[i];
        ans += tmp;
    }
    cout << ans;
    return 0;
}