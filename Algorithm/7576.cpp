// BOJ 7576 :: 토마토
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
		Pos dir[4] // 인접한 토마토
		{
			Pos{1,0},
			Pos{-1,0},
			Pos{0,1},
			Pos{0,-1}
		};
		int qsize = q.size();
		for (int j = 0; j < qsize; ++j) // 현재 레벨에서 큐에 들어와있는 토마토들을 계산하기 위함,
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
		cnt++; // 1일 증가
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
			if (vec[i][j] == 0) // 입력받을때 익지 않은 토마토들을 스택에 넣어둠
				stk.push(Pos{ i,j });
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (vec[i][j] == 1)
			{
				q.push(Pos{i,j}); // 처음부터 익어있는 토마토들을 큐에 넣어줌
				vis[i][j] = true;
			}
		}
	}
	BFS();
	while (!stk.empty()) // 탐색을 마친 후 익지 않은 토마토가 익었는지 확인한다
	{
		Pos pos = stk.top();
		stk.pop();
		if (vis[pos.x][pos.y] == false) // 익지 않았다면(BFS에서 방문하지 않았다면)
		{
			cnt = 0; // cnt를 0으로 돌린 후 반복문 탈출
			break;
		}
	}
	cout << cnt - 1; // 시작일을 계산하지 않기 때문에 1일 빼줌

	// 처음부터 난관이 있었던 토마토 문제였다. 어찌어찌 처음에 익어있는 토마토를 먼저 큐에 넣어준다는
	// 생각은 났는데, 어떻게하면 카운트(지난 날짜)를 한바퀴에 한번씩 늘려줄수 있을지가 어떻게 구현해야 하는 지 어려웠다.
	// BFS에서 깊이를체크해주면 될거 같다는 생각까지는 어찌저찌 도달해서
	// BFS 깊이를 구하는 방법을 구글링했다.ㅎ 시발

	return 0;
}