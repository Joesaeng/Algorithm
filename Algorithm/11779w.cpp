// BOJ 11779 :: 최소비용 구하기 2
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n,m;
int a, b, c;
int ans, cnt;
vector<vector<pair<int, int>>> road;
map<int, int> parent; // parent[i] = a :: i위치를 찾은 위치가 a
vector<int> path;
// 다익스트라 알고리즘
void func(int start, int dest)
{
	int pos = start;
	vector<int> dist = vector<int>(n + 1, INF);
	priority_queue<pair<int, int>> q;
	parent[pos] = pos;
	dist[pos] = 0;
	q.push(pair{ 0,pos });

	while (!q.empty())
	{
		int cost = -q.top().first;
		pos = q.top().second;
		q.pop();

		if (pos == dest)
		{
			ans = cost;
			break;
		};

		for (int i = 0; i < road[pos].size(); ++i)
		{
			int next = road[pos][i].second;
			int nCost = road[pos][i].first;
			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				parent[next] = pos;
				q.push(pair{ -dist[next], next });
			}
		}
	}
	pos = dest; // 도착지부터 역순으로 탐색
	cnt = 1;
	while (1)
	{
		path.push_back(pos); // 현재 위치를 경로에 넣는다
		if (pos == parent[pos]) // 부모가 자기 자신이면 시작점
			break;
		pos = parent[pos];
		cnt++;
	}
	reverse(path.begin(), path.end()); // 역순이니 뒤집어줌
}
int main()
{
    FASTIO;
	cin >> n >> m; // n개의 도시, m개의 버스
	road = vector<vector<pair<int, int>>>(n+1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		road[a].push_back({ c,b });
	}
	cin >> a >> b; // a에서 출발하여 b까지
	func(a, b);
	cout << ans << '\n' << cnt << '\n';
	for (auto a : path)
		cout << a << ' ';
    return 0;
}