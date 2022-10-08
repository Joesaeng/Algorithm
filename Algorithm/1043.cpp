// BOJ 1043 :: ������
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, a, b, c;
int vec[51];
int ans;
vector<vector<int>> party;
vector<bool> vis;
void func()
{
    ans = party.size();
    for (int l = 0; l < party.size(); ++l) // 3�� for���� �ݺ��Ͽ� ��Ƽ���� ���� Ȯ����
    {
        for (int i = 0; i < party.size(); ++i)
        {
            if (vis[i]) continue; // ��Ƽ�� ������ �˰� �Ǿ��ٸ� �Ѿ��
            for (int j = 0; j < party[i].size(); ++j)
            {
                if (vec[party[i][j]] == 1) // ��Ƽ�� ������ �ƴ� ����� �ִٸ�?
                {
                    vis[i] = true; // �� ��Ƽ�� ������ �˰� �Ǿ���.
                    for (int k = 0; k < party[i].size(); ++k)
                    {
                        vec[party[i][k]] = 1; // ��Ƽ������ ������ �˰��ְ� ��
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < vis.size(); ++i)
        if (vis[i]) ans--;
}
int main()
{
    FASTIO;
    cin >> n >> m; // ����� �� n, ��Ƽ�� �� m
    
    cin >> a; // ������ �ƴ� ����� ��
    for (int i = 0; i < a; ++i)
    {
        cin >> b;
        vec[b] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a; // ��Ƽ�� ���� ����� ��
        vector<int> tmp;
        bool trueman = false; // ��Ƽ�� ������ �˰� �ִ� ����� ���� ����
        for (int j = 0; j < a; ++j)
        {
            cin >> b; // ��Ƽ�� ���� ����� ��ȣ
            if (vec[b] == 1)
                trueman = true;
            tmp.push_back(b);
        }
        if (trueman) // ������ �˰��ִ� ����� �ִٸ� �� ��Ƽ�� ������ �˰� �ִ�.
        {
            for (auto x : tmp)
                vec[x] = 1; // ��°��� �ʱ�ȭ
        }
        else
            party.push_back(tmp); // �ϴ� ������ �ƴ»���� ���ٸ� party���Ϳ� �־��ش�
    }
    vis = vector<bool>(party.size(), false);
    func();
    cout << ans;
    return 0;
}