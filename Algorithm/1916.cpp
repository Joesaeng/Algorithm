// BOJ 1916 :: 최소비용 구하기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n, m;
int a, b, c;
vector<vector<pair<int, int>>> road;
int func(int start, int dest)
{
	int pos = start;
	vector<int> dist = vector<int>(n + 1, INF);
	priority_queue<pair<int, int>> q;
	dist[pos] = 0;
	q.push(pair{ 0,pos });

	while (!q.empty())
	{
		int cost = -q.top().first;
		pos = q.top().second;
		q.pop();

		if (pos == dest) return cost;

		for (int i = 0; i < road[pos].size(); ++i)
		{
			int next = road[pos][i].second;
			int nCost = road[pos][i].first;
			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				q.push(pair{ -dist[next], next });
			}
		}
	}
	return -1;
}
int main()
{
    FASTIO;
	cin >> n >> m;
	road = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		road[a].push_back(pair{ c,b });
	}
	cin >> a >> b;
	cout << func(a, b);
    return 0;
}