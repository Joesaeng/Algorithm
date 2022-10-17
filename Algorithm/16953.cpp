// BOJ 16953 :: A -> B
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll a;
ll b;
set<int> vis;
int func()
{
    queue<pair<int,int>> q;
    ll n = a;
    ll cnt = 1;
    vis.insert(n);
    q.push({ a,cnt });
    while (!q.empty())
    {
        n = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (n == b) return cnt;
        ll next = (n * 10) + 1;
        if (next <= b && vis.find(next) == vis.end())
        {
            vis.insert(n);
            q.push({ next,cnt + 1 });
        }
        next = n * 2;
        if (next <= b && vis.find(next) == vis.end())
        {
            vis.insert(n);
            q.push({ next,cnt + 1 });
        }
    }
    return -1;
}

int main()
{
    FASTIO;
    cin >> a >> b;
    cout << func();
    return 0;
}