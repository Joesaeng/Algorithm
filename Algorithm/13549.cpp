// BOJ 13549 :: ¼û¹Ù²ÀÁú 3
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF INT32_MAX
#define MAX 100001
using namespace std;
int n, k;
vector<int> dis(MAX, INF);
int func()
{
	int x = n;
	
	priority_queue<pair<int, int>> q;

	q.push(pair(0,x));
	dis[x] = 0;

	while (!q.empty())
	{
		int cost = -q.top().first;
		x = q.top().second;
		q.pop();

		int a = x + 1, b = x - 1, t = x * 2;
	
		if (x == k) return cost;

		if (a < MAX && dis[a] > cost + 1)
		{
			dis[a] = cost + 1;
			q.push(pair(-dis[a], a));
		}
		if (x > 0 && dis[b] > cost + 1)
		{
			dis[b] = cost + 1;
			q.push(pair(-dis[b], b));
		}
		if (t < MAX && dis[t] > cost)
		{
			dis[t] = cost;
			q.push(pair(-dis[t], t));
		}
	}
}

int main()
{
	FASTIO;
	cin >> n >> k;
	cout << func();

	return 0;
}