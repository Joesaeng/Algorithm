// BOJ 1043 :: 거짓말
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
    for (int l = 0; l < party.size(); ++l) // 3중 for문을 반복하여 파티들을 전부 확인함
    {
        for (int i = 0; i < party.size(); ++i)
        {
            if (vis[i]) continue; // 파티가 진실을 알게 되었다면 넘어간다
            for (int j = 0; j < party[i].size(); ++j)
            {
                if (vec[party[i][j]] == 1) // 파티에 진실을 아는 사람이 있다면?
                {
                    vis[i] = true; // 그 파티는 진실을 알게 되었다.
                    for (int k = 0; k < party[i].size(); ++k)
                    {
                        vec[party[i][k]] = 1; // 파티원들을 진실을 알고있게 함
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
    cin >> n >> m; // 사람의 수 n, 파티의 수 m
    
    cin >> a; // 진실을 아는 사람의 수
    for (int i = 0; i < a; ++i)
    {
        cin >> b;
        vec[b] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a; // 파티에 오는 사람의 수
        vector<int> tmp;
        bool trueman = false; // 파티에 진실을 알고 있는 사람의 존재 여부
        for (int j = 0; j < a; ++j)
        {
            cin >> b; // 파티에 오는 사람의 번호
            if (vec[b] == 1)
                trueman = true;
            tmp.push_back(b);
        }
        if (trueman) // 진실을 알고있는 사람이 있다면 그 파티는 진실을 알고 있다.
        {
            for (auto x : tmp)
                vec[x] = 1; // 라는것을 초기화
        }
        else
            party.push_back(tmp); // 일단 진실을 아는사람이 없다면 party벡터에 넣어준다
    }
    vis = vector<bool>(party.size(), false);
    func();
    cout << ans;
    return 0;
}