// BOJ 2667 :: 단지번호붙이기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
bool vis[27][27];
int cnt = 0;
vector<int> res;
string s;
vector<vector<int>> vec(27,(vector<int>(27,-1)));
struct Pos
{
	int x;
	int y;
};
void BFS(Pos start,int cnt)
{
	queue<Pos> q;
	q.push(start);
	vis[start.x][start.y] = true;
	Pos dir[4] // 상 하 좌 우
	{
		Pos{0,1},
		Pos{0,-1},
		Pos{1,0},
		Pos{-1,0}
	};
	while (!q.empty())
	{
		Pos pos = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			if (vis[pos.x + dir[i].x][pos.y + dir[i].y]) continue;
			if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == -1) continue;
			if (vec[pos.x + dir[i].x][pos.y + dir[i].y] == 0) continue;
			q.push(Pos{ pos.x + dir[i].x,pos.y + dir[i].y });
			vis[pos.x + dir[i].x][pos.y + dir[i].y] = true;
			res[cnt]++;
		}
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = 1; j <= n; ++j)
		{
			vec[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (vis[i][j]) continue;
			if (vec[i][j] == 0 || vec[i][j] == -1) continue;
			res.push_back(1);
			BFS(Pos{ i,j },cnt);
			cnt++;
		}
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << '\n';
	}

	return 0;
}