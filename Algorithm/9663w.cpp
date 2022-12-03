// BOJ 9663 :: N-Queen
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int ans;
vector<pair<int,int>> q; // 퀸의 위치를 담을 벡터
// 체스 퀸의 공격 범위는 가로, 세로, 대각선이다.
bool check(int y,int x)
{
    for (int i = 0; i < q.size(); ++i) // 현재 퀸 벡터에 담겨져있는 위치들을 순회
    {
        if (q[i].second == x) return false; // 이미 두어진 퀸과 x좌표가 같다면 공격받을수 있다.
        // 이미 두어진 퀸의 y - x , y + x 가 서로 같다면 대각선에 위치하기때문에 공격받을수 있다.
        if (q[i].first - q[i].second == y - x || q[i].first + q[i].second == y + x) return false;
    }
    return true;
}
void queen(int y, int x)
{
    if (y == n-1) // 마지막 줄까지 퀸을 두는데 성공했다면
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
    for (int i = 0; i < n; ++i) // (0,i) 위치에 퀸을 놓았을 때
    {
        q.push_back({ 0,i }); 
        queen(0,i);
        q.pop_back();
    }
    cout << ans;
    return 0;
}