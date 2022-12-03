// BOJ 16953 :: A -> B
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll a;
ll b;
set<int> vis; // Ʈ���� �̿��� �湮 üũ
int func()
{
    // A���� B�� ���� �������� ��ΰ� ���� �� ������
    // �ִܰ�θ� ã�� ���ؼ� BFSŽ���� �Ѵ�.
    queue<pair<int,int>> q;
    ll n = a;
    ll cnt = 1; // �ּڰ� 1
    vis.insert(n);
    q.push({ n,cnt }); // ���簪 n�� ���� ȸ�� cnt
    while (!q.empty())
    {
        n = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (n == b) return cnt;
        ll next = (n * 10) + 1; // 1�� ���� ���� �����ʿ� �߰�
        // ������ ���� �ΰ����� ������ ������ Ŀ���� �����̱� ������
        // ��ǥ�� b�� �Ѿ�ٸ� ���̻� Ž������ �ʴ´�.
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