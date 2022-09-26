// BOJ 1541 :: ÀÒ¾î¹ö¸° °ýÈ£
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string qs;
vector<int> num;
vector<char> oper;
int ans;
bool b = false;
int main()
{
    FASTIO;
    cin >> qs;
    string st;
    for (int i = 0; i < qs.length(); ++i)
    {
        if (i == qs.length() - 1)
        {
            st += qs[i];
        }
        if (i == qs.length() - 1 || qs[i] == '+' || qs[i] == '-')
        {
            if (qs[i] == '+' || qs[i] == '-') oper.push_back(qs[i]);
            int len = pow(10,st.length()-1);
            int it = 0;
            for (int j = 1; j <= len; j *= 10)
            {
                it += (st.back() - '0')* j;
                st.pop_back();
            }
            num.push_back(it);
        }
        else
        {
            st += qs[i];
        }
    }
    ans += num[0];
    int minus = 0;
    for (int i = 0; i < oper.size(); ++i)
    {
        if (b && i == oper.size() - 1 && oper[i] == '+')
        {
            minus += num[i + 1];
            ans -= minus;
        }
        else if (b && i == oper.size() - 1 && oper[i] == '-')
        {
            ans -= minus;
            ans -= num[i + 1];
        }
        else if (i == oper.size() - 1 && oper[i] == '-')
        {
            ans -= num[i + 1];
        }
        else if (b && oper[i] == '+')
        {
            minus += num[i + 1];
        }
        else if (b && oper[i] == '-')
        {
            ans -= minus;
            minus = 0;
            minus += num[i + 1];
        }
        else if (oper[i] == '+')
        {
            ans += num[i + 1];
        }
        else if (oper[i] == '-')
        {
            b = true;
            minus += num[i + 1];
        }
    }
    cout << ans;
    return 0;
}