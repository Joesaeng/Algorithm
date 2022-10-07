// BOJ 9663 :: N-Queen
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int ans;
vector<int> vAns;
vector<pair<int,int>> q;
bool check(int y,int x)
{
    for (int i = 0; i < q.size(); ++i)
    {
        if (q[i].second == x) return false;
        if (q[i].first - q[i].second == y - x || q[i].first + q[i].second == y + x) return false;
    }
    return true;
}
void queen(int y, int x)
{
    if (y == n-1)
    {
        ans++;
        return;
    }
    for (int j = 0; j < n; ++j)
    {
        if (!check(y+1,j))continue;
        q.push_back({ y+1, j });
        queen(y+1, j);
        q.pop_back();
    }
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        q.push_back({ 0,i });
        queen(0,i);
        q.pop_back();
    }
    cout << ans;
    return 0;
}