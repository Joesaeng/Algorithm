// BOJ 14502 :: ������
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, ans;
vector<vector<int>> vec; // ��
vector<pair<int,int>> s; // ���� ���� ��ġ
vector<pair<int, int>> v; // ���̷��� ��ġ
bool vis[65];
// 3���� ���� ����� ����� ���� DFS�� ã��
// BFS�� ���� ���������� ũ�⸦ �˾Ƴ���.
int BFS(vector<vector<int>> vc) // ���� �ٲٸ鼭 ã�� ������ �����ؼ� �޴´�.
{
	int ret = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); ++i)
	{
		q.push({ v[i].first,v[i].second }); // ���̷����� ��ġ�� �־���
	}
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };

	// ���̷����� ��Ʈ���� BFS
	while (!q.empty()) 
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
			if (vc[nexty][nextx] != 0) continue;
			vc[nexty][nextx] = 2;
			q.push({ nexty,nextx });
		}
	}

	// ���̷����� ��Ʈ�� �Ŀ� ���� ��ȸ�ϸ� ���������� ������ ã��
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j)
		{
			if (vc[i][j] == 0) ret++;
		}
	}
	return ret;
}
void DFS(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			vec[s[i].first][s[i].second] = 1;
		}
		ans = max(ans,BFS(vec));
		for (int i = 0; i < 3; ++i)
		{
			vec[s[i].first][s[i].second] = 0;
		}
		return;
	}
	for (int i = idx; i <= n*m; ++i)
	{
		if (vis[i]) continue;
		int nexty = (i - 1) / m;
		int nextx = (i - 1) % m;
		if (vec[nexty][nextx] != 0) continue;
		vis[i] = true;
		s.push_back({ nexty,nextx });
		DFS(i, cnt + 1);
		vis[i] = false;
		s.pop_back();
	}
}
int main()
{
    FASTIO;
    cin >> n >> m;
	vec = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
			if (vec[i][j] == 2)
				v.push_back({ i,j });
        }
    }
	DFS(1, 0);
	cout << ans;
    return 0;
}