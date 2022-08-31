// BOJ 1261 :: ¾Ë°í½ºÆÌ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
string s;
vector<vector<int>> maze(102, vector<int>(102, -1));
vector<vector<int>> dis(102, vector<int>(102,INT32_MAX));
int func()
{
	struct Pos
	{
		int x;
		int y;
		Pos(int a,int b) : x(a),y(b)
		{}
	};
	struct Myst
	{
		Pos pos;
		int cost;
	public:
		Myst(int x, int y, int t)
			: pos{x,y}, cost(t)
		{}
	};
	struct cmp
	{
		bool operator()(Myst a, Myst b)
		{
			return a.cost > b.cost;
		}
	};
	priority_queue<Myst,vector<Myst>,cmp> q;
	q.push(Myst(1,1,0));
	dis[1][1] = 0;
	while (!q.empty())
	{
		int c = q.top().cost;
		Pos pos = q.top().pos;
		q.pop();
		Pos move[4] =
		{
			Pos(pos.x,pos.y - 1),
			Pos(pos.x,pos.y + 1),
			Pos(pos.x - 1,pos.y),
			Pos(pos.x + 1,pos.y)
		};

		if (pos.x == n && pos.y == m) return c;

		for (int i = 0; i < 4; ++i)
		{
			if (move[i].x > 0 && move[i].y > 0 && maze[move[i].x][move[i].y] == 0 && dis[move[i].x][move[i].y] > c)
			{
				dis[move[i].x][move[i].y] = c;
				q.push(Myst(move[i].x, move[i].y, c));
			}
			if (move[i].x > 0 && move[i].y > 0 && maze[move[i].x][move[i].y] == 1 && dis[move[i].x][move[i].y] > c + 1)
			{
				dis[move[i].x][move[i].y] = c + 1;
				q.push(Myst(move[i].x, move[i].y, c + 1));
			}
		}
	}
}

int main()
{
	FASTIO;
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
		{
			maze[i + 1][j + 1] = s[j] - '0';
		}
	}
	cout << func();

	return 0;
}