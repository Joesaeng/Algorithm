// BOJ 12908 :: �ڷ���Ʈ 3
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll xs, ys, xe, ye, ans=9876543210;
ll x1[3], yy[3], x2[3], y2[3];
struct Pos
{
    ll y = 0; // y��ǥ
    ll x = 0; // x��ǥ
    ll time = 0;
    bool use1[3] = { false, }; // x1y1 -> x2y2 �ڷ���Ʈ �̿� �ߴ���
    bool use2[3] = { false, }; // x2y2 -> x1y1 �ڷ���Ʈ �̿� �ߴ���
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
        // ������ǥ(pos.y,pos.x)���� ������(ye,xe) ���� �����θ� �̵��Ͽ� �ɸ��� �ð�
        ans = min(ans, abs(ye - pos.y) + abs(xe - pos.x) + pos.time); 
        for (int i = 0; i < 3; ++i)
        {
            if (pos.use1[i]) continue; // ���� ��ǥ�� �ڷ���Ʈ�� ����ؼ� �� ������?
            Pos next = pos;
            next.use1[i] = true;
            // ������ġ(next.y,next.x)���� �ڷ���Ʈ ������(yy(y1),x1)���� �ɸ��� �ð� + �ڷ���Ʈ �̿� �ð� 
            next.time += abs(yy[i] - pos.y) + abs(x1[i] - pos.x) + 10;
            next.y = y2[i];
            next.x = x2[i];
            q.push(next);
        }
        for (int i = 0; i < 3; ++i)
        {
            if (pos.use2[i]) continue; // ���� ��ǥ�� �ڷ���Ʈ�� ����ؼ� �� ������?
            Pos next = pos;
            next.use2[i] = true;
            // ������ġ(next.y,next.x)���� �ڷ���Ʈ ������(yy(y1),x1)���� �ɸ��� �ð� + �ڷ���Ʈ �̿� �ð� 
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