// BOJ 12908 :: 텔레포트 3
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll xs, ys, xe, ye, ans=9876543210;
ll x1[3], yy[3], x2[3], y2[3];
struct Pos
{
    ll y = 0; // y좌표
    ll x = 0; // x좌표
    ll time = 0;
    bool use1[3] = { false, }; // x1y1 -> x2y2 텔레포트 이용 했는지
    bool use2[3] = { false, }; // x2y2 -> x1y1 텔레포트 이용 했는지
};
void BFS()
{
    queue<Pos> q;
    Pos pos;
    pos.y = ys;
    pos.x = xs;
    q.push(pos);
    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        // 현재좌표(pos.y,pos.x)에서 도착지(ye,xe) 까지 점프로만 이동하여 걸리는 시간
        ans = min(ans, abs(ye - pos.y) + abs(xe - pos.x) + pos.time); 
        for (int i = 0; i < 3; ++i)
        {
            if (pos.use1[i]) continue; // 지금 좌표가 텔레포트를 사용해서 온 것인지?
            Pos next = pos;
            next.use1[i] = true;
            // 현재위치(next.y,next.x)에서 텔레포트 시작점(yy(y1),x1)까지 걸리는 시간 + 텔레포트 이용 시간 
            next.time += abs(yy[i] - pos.y) + abs(x1[i] - pos.x) + 10;
            next.y = y2[i];
            next.x = x2[i];
            q.push(next);
        }
        for (int i = 0; i < 3; ++i)
        {
            if (pos.use2[i]) continue; // 지금 좌표가 텔레포트를 사용해서 온 것인지?
            Pos next = pos;
            next.use2[i] = true;
            // 현재위치(next.y,next.x)에서 텔레포트 시작점(yy(y1),x1)까지 걸리는 시간 + 텔레포트 이용 시간 
            next.time += abs(y2[i] - pos.y) + abs(x2[i] - pos.x) + 10;
            next.y = yy[i];
            next.x = x1[i];
            q.push(next);
        }
    }
}
int main()
{
    FASTIO;
    cin >> xs >> ys >> xe >> ye;
    for (int i = 0; i < 3; ++i)
        cin >> x1[i] >> yy[i] >> x2[i] >> y2[i];
    BFS();
    cout << ans;
    return 0;
}