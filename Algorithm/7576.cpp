// BOJ 7576 :: �丶��
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
vector<vector<int>> vec(1002, vector<int>(1002, -2));
bool vis[1001][1001];
int cnt = 0;
struct Pos
{
	int x;
	int y;
};
queue<Pos> q;
stack<Pos> stk;
void BFS()
{
	while (!q.empty())
	{
		Pos dir[4] // ������ �丶��
		{
			Pos{1,0},
			Pos{-1,0},
			Pos{0,1},
			Pos{0,-1}
		};
		int qsize = q.size();
		for (int j = 0; j < qsize; ++j) // ���� �������� ť�� �����ִ� �丶����� ����ϱ� ����,
		{
			Pos pos = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				if (vis[pos.x + dir[i].x][pos.y + dir[i].y]) continue;
				if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == 0)
				{
					q.push(Pos{ pos.x + dir[i].x, pos.y + dir[i].y });
					vis[pos.x + dir[i].x][pos.y + dir[i].y] = true;
				}
			}
		}
		cnt++; // 1�� ����
	}
}
int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> vec[i][j];
			if (vec[i][j] == 0) // �Է¹����� ���� ���� �丶����� ���ÿ� �־��
				stk.push(Pos{ i,j });
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (vec[i][j] == 1)
			{
				q.push(Pos{i,j}); // ó������ �;��ִ� �丶����� ť�� �־���
				vis[i][j] = true;
			}
		}
	}
	BFS();
	while (!stk.empty()) // Ž���� ��ģ �� ���� ���� �丶�䰡 �;����� Ȯ���Ѵ�
	{
		Pos pos = stk.top();
		stk.pop();
		if (vis[pos.x][pos.y] == false) // ���� �ʾҴٸ�(BFS���� �湮���� �ʾҴٸ�)
		{
			cnt = 0; // cnt�� 0���� ���� �� �ݺ��� Ż��
			break;
		}
	}
	cout << cnt - 1; // �������� ������� �ʱ� ������ 1�� ����

	// ó������ ������ �־��� �丶�� ��������. ������� ó���� �;��ִ� �丶�並 ���� ť�� �־��شٴ�
	// ������ ���µ�, ����ϸ� ī��Ʈ(���� ��¥)�� �ѹ����� �ѹ��� �÷��ټ� �������� ��� �����ؾ� �ϴ� �� �������.
	// BFS���� ���̸�üũ���ָ� �ɰ� ���ٴ� ���������� �������� �����ؼ�
	// BFS ���̸� ���ϴ� ����� ���۸��ߴ�.�� �ù�

	return 0;
}