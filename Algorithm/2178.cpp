// BOJ 2178 :: 미로 탐색
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
vector<vector<int>> vec(102, vector<int>(102, -1));
bool vis[101][101];
int cnt = 0;
string s;
struct Pos
{
	int x;
	int y;
	bool operator==(Pos& other)
	{
		if (x == other.x)
			if (y == other.y) return true;
		return false;
	}
	bool operator<(const Pos& other) const
	{
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}
};
void di()
{
	queue<Pos> q;
	Pos pos = Pos{ 1,1 };
	q.push(pos);
	vis[1][1] = true;
	map<Pos,Pos> parent;
	parent[pos] = pos;
	Pos dir[4]
	{
		Pos{0,1},
		Pos{0,-1},
		Pos{1,0},
		Pos{-1,0},
	};

	while (!q.empty())
	{
		pos = q.front();
		q.pop();

		if (pos.x == n && pos.y == m)
			break;

		for (int i = 0; i < 4; ++i)
		{
			Pos next = Pos{ pos.x + dir[i].x,pos.y + dir[i].y };
			if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == -1 || // 범위를 벗어낫을 때
				vec[pos.x + dir[i].x][pos.y + dir[i].y] == 0) /* 갈수 없는 땅일 때*/continue;
			if (vis[pos.x + dir[i].x][pos.y + dir[i].y]) /*이미 방문했을 때*/ continue;
			q.push(next);
			parent[next] = pos;
			vis[pos.x + dir[i].x][pos.y + dir[i].y] = true;
		}
	}
	pos = Pos{ n,m };
	while (1)
	{
		cnt++;
		if (pos == parent[pos]) break;
		pos = parent[pos];
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
			vec[i][j] = s[j - 1] - '0';
		}
	}
	di();
	cout << cnt;

	return 0;
}