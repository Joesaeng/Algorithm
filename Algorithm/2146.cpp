// BOJ 2146 :: 다리 만들기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<vector<int>> board;
vector<vector<int>> land;
vector<vector<bool>> vis;
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
void island(int y,int x) // 각 섬의 번호를 붙여주는 BFS
{
	queue<Pos> q;
	Pos pos = Pos{y,x};
	q.push(pos);
	vis[pos.y][pos.x] = true;
	land[pos.y][pos.x] = sNum;
	int dirY[4] = { 1,-1,0,0 };
	int dirX[4] = { 0,0,1,-1 };
	
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
			if (board[nextY][nextX] == 0) continue;
			if (vis[nextY][nextX]) continue;
			q.push(next);
			vis[nextY][nextX] = true;
			land[nextY][nextX] = sNum;
		}
	}
}
void BFS(int y, int x, int num)
{
	queue<Pos> q;
	Pos pos = Pos{ y,x };
	q.push(pos);
	vis[pos.y][pos.x] = true;
	int dirY[4] = { 1,-1,0,0 };
	int dirX[4] = { 0,0,1,-1 };

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
			if (board[nextY][nextX] == 0)
			{
				next.cnt = pos.cnt + 1;
				q.push(next);
				vis[nextY][nextX] = true;
			}
			else if (land[nextY][nextX] != num)
			{
				ans = min(ans, pos.cnt);
			}
		}
	}
}
int main()
{
	FASTIO;
	cin >> n;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1,-1));
	land = vector<vector<int>>(n + 1, vector<int>(n + 1,-1));
	vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1,false));
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
			if (land[i][j] != -1) continue;
			if (vis[i][j]) continue;
			island(i, j);
			sNum++;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] == 0) continue;
			vis = vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
			BFS(i,j,land[i][j]);
		}
	}
	cout << ans;
	return 0;
}