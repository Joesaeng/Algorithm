// BOJ 15686 :: 치킨 배달
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, t;
vector<pair<int, int>> home; // 집의 위치
vector<pair<int, int>> cHome; // 치킨집의 위치
vector<bool> vis; 
vector<int> sel;
int ans = 987654321;
void DFS(int idx, int cnt) 
{
    // 조합을 통해 폐업하지 않을 m개의 치킨집을 구하는 경우의 수를 찾아 치킨거리를 구한다
    if (cnt == m) // m개의 치킨집을 선택
    {
        int tAns=0;
        for (int i = 0; i < home.size(); ++i) // 각 집에서의 치킨거리 중 최소를 구한다
        {
            int tmp = 987654321;
            for (int j = 0; j < m; ++j)
            {
                tmp = min(tmp,abs(cHome[sel[j]].first - home[i].first) 
                    + abs(cHome[sel[j]].second - home[i].second));
                //   현재 선택한 치킨집과 각 집들의 거리를 구함
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
        sel.push_back(i); // 선택한 치킨집의 인덱스를 저장
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
                home.push_back({ i,j }); // 집의 좌표 (i,j)
            if (t == 2)
                cHome.push_back({ i,j }); // 치킨집의 좌표 (i,j)
        }
    }
    vis = vector<bool>(cHome.size(),false);
    DFS(0, 0);
    cout << ans;
    return 0;
}