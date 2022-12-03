// BOJ 11404 :: �÷��̵�
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 987654321
int n, m,a,b,c;
vector<vector<int>> bus;
// ���� �̸��� �����ϰ� �÷��̵�ͼ� �˰��� ������.
int main()
{
    FASTIO;
    cin >> n >> m;
    bus = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) bus[i][i] = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        // ���� ��ΰ� �־��� �� ������ �ִ� ��θ� ���Ͽ��� �ϴ� ���� ���� ����
        if (bus[a][b] > c) bus[a][b] = c; 
    }
    for (int k = 1; k <= n; ++k) // ���İ��� ����
        for (int i = 1; i <= n; ++i) // ���� ����
            for (int j = 1; j <=n; ++j) // ���� ����
            {
                if (bus[i][k] + bus[k][j] < bus[i][j])
                    bus[i][j] = bus[i][k] + bus[k][j];
            }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (bus[i][j] == INF) cout << "0 ";
            else cout << bus[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}