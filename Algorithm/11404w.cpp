// BOJ 11404 :: 플로이드
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 987654321
int n, m,a,b,c;
vector<vector<int>> bus;
// 문제 이름과 동일하게 플로이드와샬 알고리즘 문제다.
int main()
{
    FASTIO;
    cin >> n >> m;
    bus = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) bus[i][i] = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        // 같은 경로가 주어질 떄 어차피 최단 경로를 구하여야 하니 작은 값만 저장
        if (bus[a][b] > c) bus[a][b] = c; 
    }
    for (int k = 1; k <= n; ++k) // 거쳐가는 정점
        for (int i = 1; i <= n; ++i) // 시작 정점
            for (int j = 1; j <=n; ++j) // 도착 정점
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