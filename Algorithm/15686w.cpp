// BOJ 15686 :: ġŲ ���
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, t;
vector<pair<int, int>> home; // ���� ��ġ
vector<pair<int, int>> cHome; // ġŲ���� ��ġ
vector<bool> vis; 
vector<int> sel;
int ans = 987654321;
void DFS(int idx, int cnt) 
{
    // ������ ���� ������� ���� m���� ġŲ���� ���ϴ� ����� ���� ã�� ġŲ�Ÿ��� ���Ѵ�
    if (cnt == m) // m���� ġŲ���� ����
    {
        int tAns=0;
        for (int i = 0; i < home.size(); ++i) // �� �������� ġŲ�Ÿ� �� �ּҸ� ���Ѵ�
        {
            int tmp = 987654321;
            for (int j = 0; j < m; ++j)
            {
                tmp = min(tmp,abs(cHome[sel[j]].first - home[i].first) 
                    + abs(cHome[sel[j]].second - home[i].second));
                //   ���� ������ ġŲ���� �� ������ �Ÿ��� ����
            }
            tAns += tmp;
        }
        ans = min(ans,tAns);
        return;
    }
    for (int i = idx; i < cHome.size(); ++i)
    {
        if (vis[i]) continue;
        vis[i] = true;
        sel.push_back(i); // ������ ġŲ���� �ε����� ����
        DFS(i, cnt + 1);
        sel.pop_back();
        vis[i] = false;
    }
}
int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> t;
            if (t == 1)
                home.push_back({ i,j }); // ���� ��ǥ (i,j)
            if (t == 2)
                cHome.push_back({ i,j }); // ġŲ���� ��ǥ (i,j)
        }
    }
    vis = vector<bool>(cHome.size(),false);
    DFS(0, 0);
    cout << ans;
    return 0;
}