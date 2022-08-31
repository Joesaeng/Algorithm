// BOJ 14226 :: 이모티콘
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 2000
using namespace std;
int s;
bool visited[MAX][MAX];
int func()
{
	struct imo
	{
		int dis;
		int clip;
		int time;
	public:
		imo(int d,int c,int t)
			: dis(d),clip(c),time(t)
		{}
	};
	queue<imo> q;
	q.push(imo(1, 0, 0));
	visited[1][0] = true;

	while (!q.empty())
	{
		int d = q.front().dis;
		int c = q.front().clip;
		int t = q.front().time;
		q.pop();

		if (d == s) return t;

		if (d > 0 && d < MAX)
		{
			if (!visited[d][d])
			{
				visited[d][d] = true;
				q.push(imo(d, d, t + 1));
			}
			if (!visited[d - 1][c])
			{
				visited[d - 1][c] = true;
				q.push(imo(d - 1, c, t + 1));
			}
		}
		if (d > 0 && d + c < MAX)
		{
			if (!visited[d + c][c])
			{
				visited[d + c][c] = true;
				q.push(imo(d + c, c, t + 1));
			}
		}
	}
}

int main()
{
	FASTIO;
	cin >> s;
	cout << func();

	return 0;
}