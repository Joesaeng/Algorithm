// BOJ 1966 :: 프린터 큐
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, t, x;
queue<pair<int,int>> q;
void func()
{
	int i = 1;
	while (!q.empty())
	{
		queue<pair<int, int>> tq = q;
		while(!q.empty() && !tq.empty())
		{
			if (!tq.empty() && q.front().first < tq.front().first)
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				if(!tq.empty())
					tq.pop();
			}
		}
		if (q.front().second == m)
		{
			cout << i << '\n';
			break;
		}
		else
		{
			if (!q.empty())
			{
				q.pop();
				++i;
			}

		}
	}
}

int main()
{
	FASTIO;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			q.push(pair(x,i));
		}
		func();
		while (!q.empty())
			q.pop();
	}

	return 0;
}