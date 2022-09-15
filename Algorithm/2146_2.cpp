// BOJ 2146 :: 다리 만들기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<vector<int>> board; // 지도를 입력받고 섬의 번호를 매겨줄 배열
vector<vector<bool>> vis; // 방문
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
bool Out(int y, int x) // 현재 위치가 섬의 가장자리인지 확인해주는 bool 함수
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
void island(int y, int x) // 각 섬의 번호를 붙여주는 BFS
{
	queue<Pos> q;
	Pos pos = Pos{ y,x };
	q.push(pos);
	vis[pos.y][pos.x] = true;
	board[pos.y][pos.x] = sNum; // sNum == 1번부터 ++
	
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) // 동서남북 방향으로 돌린다
		{
			int nextY = pos.y + dirY[i];
			int nextX = pos.x + dirX[i];
			Pos next = Pos{ nextY,nextX };
			if (!next.Cango()) continue; // 갈수있는 자리인지
			if (board[nextY][nextX] == 0) continue; // 바다라면 넘어간다
			if (vis[nextY][nextX]) continue; // 이미 방문했다면 넘어간다
			q.push(next);
			vis[nextY][nextX] = true;
			board[nextY][nextX] = sNum; // 이번 island 함수에서 찾는 모든 위치를 같은 번호(sNum)으로 매겨준다
		}
	}
}
void BFS(int y, int x, int num) // 섬의 가장자리에서부터 다음 섬을 찾는 BFS
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
			if (board[nextY][nextX] == 0) // 바다(0)라면 다리를 놓는다
			{
				next.cnt = pos.cnt + 1; // 다리의 길이
				q.push(next);
				vis[nextY][nextX] = true;
			}
			else if (board[nextY][nextX] != num) // 이번에 찾은 위치가 바다가 아니고, 현재 섬과 다른 섬이라면
			{
				ans = min(ans, pos.cnt); // 최소값을 갱신해주고 리턴한다
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
			sNum++; // 섬의 번호를 1번부터 번호순으로 매겨주기 위함
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