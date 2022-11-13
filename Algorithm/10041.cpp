// BOJ 10041 :: °ü±¤
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int w, h, n, ans;
int BFS(int by, int bx,int ey, int ex)
{
    queue<pair<int, pair<int,int>>> q;
    q.push({ by,{bx,0 } });
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (y == ey && x == ex) 
        {
            return cost;
        }
        if (y < ey && x < ex)
        {
            q.push({ y + 1,{x + 1,cost + 1} });
        }
        else if (y > ey && x > ex)
        {
            q.push({ y - 1,{x - 1,cost + 1} });
        }
        else if (y > ey && x < ex)
        {
            q.push({ y - 1,{x,cost + 1} });
        }
        else if (y < ey && x > ex)
        {
            q.push({ y + 1,{x,cost + 1} });
        }
        else if (y == ey)
        {
            if (x < ex)
            {
                return cost + ex - x;
            }
            else
            {
                return cost + x - ex;
            }
        }
        else if (x == ex)
        {
            if (y < ey)
            {
                return cost + ey - y;
            }
            else
            {
                return cost + y - ey;
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> w >> h >> n;
    int a, b, c, d;
    cin >> a >> b;
    n--;
    while (n--)
    {
        cin >> c >> d;
        ans += BFS(a, b, c, d);
        a = c;
        b = d;
    }
    cout << ans;
    
    
    return 0;
}