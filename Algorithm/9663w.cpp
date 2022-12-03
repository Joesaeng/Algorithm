// BOJ 9663 :: N-Queen
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int ans;
vector<pair<int,int>> q; // ���� ��ġ�� ���� ����
// ü�� ���� ���� ������ ����, ����, �밢���̴�.
bool check(int y,int x)
{
    for (int i = 0; i < q.size(); ++i) // ���� �� ���Ϳ� ������ִ� ��ġ���� ��ȸ
    {
        if (q[i].second == x) return false; // �̹� �ξ��� ���� x��ǥ�� ���ٸ� ���ݹ����� �ִ�.
        // �̹� �ξ��� ���� y - x , y + x �� ���� ���ٸ� �밢���� ��ġ�ϱ⶧���� ���ݹ����� �ִ�.
        if (q[i].first - q[i].second == y - x || q[i].first + q[i].second == y + x) return false;
    }
    return true;
}
void queen(int y, int x)
{
    if (y == n-1) // ������ �ٱ��� ���� �δµ� �����ߴٸ�
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
    for (int i = 0; i < n; ++i) // (0,i) ��ġ�� ���� ������ ��
    {
        q.push_back({ 0,i }); 
        queen(0,i);
        q.pop_back();
    }
    cout << ans;
    return 0;
}