// BOJ 1927 :: ÃÖ¼Ò Èü
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t;
int main()
{
    FASTIO;
    cin >> t;
    int a;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < t; ++i)
    {
        cin >> a;
        if (a == 0)
        {
            if (q.empty())
                cout << "0" << '\n';
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
        {
            q.push(a);
        }
    }
    return 0;
}