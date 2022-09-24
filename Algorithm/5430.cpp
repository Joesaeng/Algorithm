// BOJ 5430 :: AC
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t,n;
string p;
string x;
int main()
{
    FASTIO;
    cin >> t;
    for(int k = 0; k < t; ++k)
    {
        deque<int> dq;
        cin >> p;
        cin >> n;
        cin >> x;
        string tmp;
        int re = -1;
        bool b = true;
        for (int i = 1; i < x.length() - 1; ++i)
        {
            if (x[i] == ',')
            {
                if (tmp.size() == 3)
                {
                    dq.push_back(100);
                }
                else if (tmp.size() == 2)
                {
                    int x = tmp[0] * 10;
                    x += tmp[1];
                    dq.push_back(x);
                }
                else if (tmp.size() == 1)
                {
                    dq.push_back(tmp[0]);
                }
                tmp = "";
            }
            else if (i == x.length() - 2)
            {
                tmp += x[i] - '0';
                if (tmp.size() == 3)
                {
                    dq.push_back(100);
                }
                else if (tmp.size() == 2)
                {
                    int x = tmp[0] * 10;
                    x += tmp[1];
                    dq.push_back(x);
                }
                else if (tmp.size() == 1)
                {
                    dq.push_back(tmp[0]);
                }
            }
            else
            {
                tmp += x[i] - '0';
            }
        }
        for (int i = 0; i < p.length(); ++i)
        {
            if (dq.empty() && p[i] == 'D')
            {
                cout << "error" << '\n';
                b = false;
                break;
            }
            if (p[i] == 'R')
            {
                re *= -1;
            }
            if (p[i] == 'D')
            {
                if (re == 1)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (b)
        {
            cout << '[';
            if (!dq.empty())
            {
                if (re == -1)
                {
                    while (dq.size() > 1)
                    {
                        cout << dq.front() << ',';
                        dq.pop_front();
                    }
                }
                else
                {
                    while (dq.size() > 1)
                    {
                        cout << dq.back() << ',';
                        dq.pop_back();
                    }
                }
                cout << dq.front();
                dq.pop_front();
            }
            
            cout << ']' << '\n';
        }
    }

    return 0;
}