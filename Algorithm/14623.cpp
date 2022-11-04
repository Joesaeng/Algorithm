// BOJ 14623 :: °¨Á¤ÀÌÀÔ(2Áø¼ö °ö¼À)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string Sum(string left, string right)
{
    int sum = 0;
    string ret;
    
    while (!left.empty() || !right.empty() || sum)
    {
        if (!left.empty())
        {
            sum += left.back() - '0';
            left.pop_back();
        }
        if (!right.empty())
        {
            sum += right.back() - '0';
            right.pop_back();
        }
        ret.push_back((sum % 2) + '0');
        sum /= 2;
    }
    reverse(ret.begin(), ret.end());



    return ret;
}
int main()
{
    string a, b;
    vector<string> vec;
    cin >> a >> b;
    for (int i = b.length()-1; i >= 0; --i)
    {
        if (b[i] == '0') continue;
        string t;
        for (int j = b.length()-1; j > i; --j)
        {
            t += '0';
        }
        for (int j = a.length()-1; j >= 0; --j)
        {
            if (b[i] == '1' && a[j] == '1')
                t += '1';
            else
                t += '0';
        }
        reverse(t.begin(), t.end());
        vec.push_back(t);
    }
    string ans = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        ans = Sum(ans, vec[i]);
    }
    cout << ans;
    return 0;
}