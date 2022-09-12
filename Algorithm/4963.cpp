// BOJ 4963 :: 섬의 개수
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int w,h;
bool vis[51][51];
int cnt = 0;
struct Pos
{
	int x;
	int y;
};
void BFS(Pos start, int cnt, vector<vector<int>>& vec)
{
	queue<Pos> q;
	q.push(start);
	vis[start.x][start.y] = true;
	Pos dir[8] // 상 하 좌 우 // 대각선
	{
		Pos{0,1},
		Pos{0,-1},
		Pos{1,0},
		Pos{-1,0},
		Pos{-1,1},
		Pos{-1,-1},
		Pos{1,-1},
		Pos{1,1}
	};
	while (!q.empty())
	{
		Pos pos = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			if (vis[pos.x + dir[i].x][pos.y + dir[i].y]) continue;
			if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == -1) continue;
			if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == 0) continue;
			q.push(Pos{ pos.x + dir[i].x,pos.y + dir[i].y });
			vis[pos.x + dir[i].x][pos.y + dir[i].y] = true;
		}
	}
}

int main()
{
	FASTIO;
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		vector<vector<int>> vec(52, (vector<int>(52, -1)));
		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				cin >> vec[i][j];
			}
		}
		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				if (vis[i][j]) continue;
				if (vec[i][j] == 0 || vec[i][j] == -1) continue;
				cnt++;
				BFS(Pos{ i,j }, cnt, vec);
			}
		}
		cout << cnt << '\n';
		cnt = 0;
		memset(vis, 0, sizeof(vis));
	}
	

	return 0;
}