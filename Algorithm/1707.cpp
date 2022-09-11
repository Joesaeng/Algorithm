// BOJ 1707 :: 이분 그래프
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, v, e;
int vis[20001];
bool check;
vector<vector<int>> vec;
void BFS(int start, int color)
{
	queue<int> q;
	int x = start;
	q.push(x);
	vis[x] = color;
	while (!q.empty() && check)
	{
		x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); ++i)
		{
			if (!vis[vec[x][i]]) // 방문하지 않은 정점이라면 queue에 담는다
			{
				q.push(vec[x][i]);
				vis[vec[x][i]] = vis[x] * -1;   // 방문할 정점의 색을 현재 색과 반전되게 -1을 곱해준다.
												//(방문한 정점의 색은 1 or -1, 방문하지않은 정점은 0)
			}
			else if (vis[x] == vis[vec[x][i]]) // 현재 방문한 정점과 이어진 정점의 색이 같다면 이분 그래프가 아니다.
			{
				check = false;
				return;
			}
		}
	}
}

int main()
{
	FASTIO;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		vec.clear();
		cin >> v >> e;
		vec.resize(v + 1);
		for (int j = 0; j < e; ++j) // 인접 그래프 생성
		{
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		check = true;
		for (int i = 1; i < v + 1; ++i)
		{
			if (!check) break; // 이분그래프가 아니라면 반복문 탈출
			if (vis[i]) continue; // 이미 방문한 정점은 넘어감
			BFS(i,1); // BFS로 모든 정점 탐색
		}
		
		memset(vis, 0, 20001 * sizeof(int)); // 색 초기화
		if (check) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}


	return 0;
}