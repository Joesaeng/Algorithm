// BOJ 1707 :: �̺� �׷���
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, v, e;
int vis[20001];
bool check;
vector<vector<int>> vec;
void BFS(int start, int color)
{
	queue<int> q;
	int x = start;
	q.push(x);
	vis[x] = color;
	while (!q.empty() && check)
	{
		x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); ++i)
		{
			if (!vis[vec[x][i]]) // �湮���� ���� �����̶�� queue�� ��´�
			{
				q.push(vec[x][i]);
				vis[vec[x][i]] = vis[x] * -1;   // �湮�� ������ ���� ���� ���� �����ǰ� -1�� �����ش�.
												//(�湮�� ������ ���� 1 or -1, �湮�������� ������ 0)
			}
			else if (vis[x] == vis[vec[x][i]]) // ���� �湮�� ������ �̾��� ������ ���� ���ٸ� �̺� �׷����� �ƴϴ�.
			{
				check = false;
				return;
			}
		}
	}
}

int main()
{
	FASTIO;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		vec.clear();
		cin >> v >> e;
		vec.resize(v + 1);
		for (int j = 0; j < e; ++j) // ���� �׷��� ����
		{
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		check = true;
		for (int i = 1; i < v + 1; ++i)
		{
			if (!check) break; // �̺б׷����� �ƴ϶�� �ݺ��� Ż��
			if (vis[i]) continue; // �̹� �湮�� ������ �Ѿ
			BFS(i,1); // BFS�� ��� ���� Ž��
		}
		
		memset(vis, 0, 20001 * sizeof(int)); // �� �ʱ�ȭ
		if (check) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}


	return 0;
}