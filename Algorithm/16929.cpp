// BOJ 16929 :: Two Dots
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
string s;
char board[51][51];
bool vis[51][51];
bool ans;
struct Pos
{
	int y = 0;
	int x = 0;
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
		return y >= 1 && x >= 1 && y <= n&& x <= m;
	}
};
Pos dir[4] =
{
	Pos{1,0},
	Pos{0,1},
	Pos{-1,0},
	Pos{0,-1},
};
Pos start;
void DFS(char color, Pos yx, int begin)
{
	if (begin >= 4 && yx == start)
	{
		ans = true;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		Pos nextPos = yx + dir[i];
		if (!nextPos.Cango()) continue;
		if (board[nextPos.y][nextPos.x] != color) continue;
		if (!vis[nextPos.y][nextPos.x])
		{
			vis[nextPos.y][nextPos.x] = true;
			DFS(color, nextPos, begin + 1);
		}
		else if (nextPos == start && begin >= 4)
		{
			ans = true;
			return;
		}
	}
}
int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = 1; j <= m; ++j)
		{
			board[i][j] = s[j - 1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (ans) break;
			memset(vis, false, sizeof(vis));
			start = Pos{ i,j };
			vis[i][j] = true;
			DFS(board[i][j], Pos{i,j}, 1);
		}
	}
	if (ans) cout << "Yes";
	else cout << "No";
	return 0;
}