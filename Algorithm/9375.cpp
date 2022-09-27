// BOJ 9375 :: ÆÐ¼Ç¿Õ ½ÅÇØºó
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t,n;
string a, b;
vector<vector<int>> vec;
int ans;
int main()
{
    FASTIO;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> hav;
        vec.clear();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            bool hv = false;
            int ti = -1;
            for (int j = 0; j < hav.size(); ++j)
            {
                if (j > hav.size() - j - 1) break;
                if (hav[j] == b)
                {
                    hv = true;
                    ti = j;
                    break;
                }
                else if (hav[hav.size() - j - 1] == b)
                {
                    hv = true;
                    ti = hav.size() - j - 1;
                    break;
                }
            }
            if (!hv)
            {
                hav.push_back(b);
                vec.push_back(vector<int>(1,0));
                vec[cnt].push_back(vec[cnt].back() + 1);
                cnt++;
            }
            else
            {
                vec[ti].push_back(vec[ti].back() + 1);
            }
        }
        ans = 1;
        for (int i = 0; i < vec.size(); ++i)
        {
            ans *= vec[i].size();
        }
        cout << ans - 1<< '\n';
        ans = 0;
    }
    return 0;
}