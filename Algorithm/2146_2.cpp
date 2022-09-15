// BOJ 2146 :: �ٸ� �����
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<vector<int>> board; // ������ �Է¹ް� ���� ��ȣ�� �Ű��� �迭
vector<vector<bool>> vis; // �湮
int n;
struct Pos
{
	int y = 0;
	int x = 0;
	int cnt = 0;
	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}
	bool Cango()
	{
		return y >= 1 && x >= 1 && y <= n && x <= n;
	}
};
int sNum = 1;
int ans = INT32_MAX;
int dirY[4] = { 1,-1,0,0 };
int dirX[4] = { 0,0,1,-1 };
bool Out(int y, int x) // ���� ��ġ�� ���� �����ڸ����� Ȯ�����ִ� bool �Լ�
{
	if (y > 1)
		if (board[y - 1][x] == 0)
			return true;
	if (x > 1)
		if (board[y][x-1] == 0)
			return true;
	if (y < n - 1)
		if (board[y + 1][x] == 0)
			return true;
	if (x < n - 1)
		if (board[y][x + 1] == 0)
			return true;
	return false;
}
void island(int y, int x) // �� ���� ��ȣ�� �ٿ��ִ� BFS
{
	queue<Pos> q;
	Pos pos = Pos{ y,x };
	q.push(pos);
	vis[pos.y][pos.x] = true;
	board[pos.y][pos.x] = sNum; // sNum == 1������ ++
	
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) // �������� �������� ������
		{
			int nextY = pos.y + dirY[i];
			int nextX = pos.x + dirX[i];
			Pos next = Pos{ nextY,nextX };
			if (!next.Cango()) continue; // �����ִ� �ڸ�����
			if (board[nextY][nextX] == 0) continue; // �ٴٶ�� �Ѿ��
			if (vis[nextY][nextX]) continue; // �̹� �湮�ߴٸ� �Ѿ��
			q.push(next);
			vis[nextY][nextX] = true;
			board[nextY][nextX] = sNum; // �̹� island �Լ����� ã�� ��� ��ġ�� ���� ��ȣ(sNum)���� �Ű��ش�
		}
	}
}
void BFS(int y, int x, int num) // ���� �����ڸ��������� ���� ���� ã�� BFS
{
	queue<Pos> q;
	Pos pos = Pos{ y,x };
	q.push(pos);
	vis[pos.y][pos.x] = true;

	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextY = pos.y + dirY[i];
			int nextX = pos.x + dirX[i];
			Pos next = Pos{ nextY,nextX };
			if (!next.Cango()) continue;
			if (vis[nextY][nextX]) continue;
			if (board[nextY][nextX] == 0) // �ٴ�(0)��� �ٸ��� ���´�
			{
				next.cnt = pos.cnt + 1; // �ٸ��� ����
				q.push(next);
				vis[nextY][nextX] = true;
			}
			else if (board[nextY][nextX] != num) // �̹��� ã�� ��ġ�� �ٴٰ� �ƴϰ�, ���� ���� �ٸ� ���̶��
			{
				ans = min(ans, pos.cnt); // �ּҰ��� �������ְ� �����Ѵ�
				return;
			}
		}
	}
}
int main()
{
	FASTIO;
	cin >> n;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
	vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] == 0) continue;
			if (vis[i][j]) continue;
			island(i, j);
			sNum++; // ���� ��ȣ�� 1������ ��ȣ������ �Ű��ֱ� ����
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] == 0 || !Out(i,j)) continue;
			vis = vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
			BFS(i, j, board[i][j]);
		}
	}
	cout << ans;
	return 0;
}