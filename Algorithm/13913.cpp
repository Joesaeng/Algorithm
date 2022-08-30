// BOJ 13913 :: ¼û¹Ù²ÀÁú 4
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k;
void func()
{
	int x = n;
	bool dis[100001] = { false, };
	vector<int> path;
	map<int, int> m;
	int sec = 0;

	queue<int> q;
	q.push(x);
	dis[x] = true;
	m[x] = x;

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		int a = x + 1, b = x - 1, t = x * 2;
		int move[3] = { a,b,t };
		if (x == k)
			break;
		for (int i = 0; i < 3; ++i)
		{
			int temp = move[i];
			if (temp < 0 || temp > 100000) continue;
			if (dis[temp]) continue;

			q.push(temp);
			dis[temp] = true;
			m[temp] = x;
		}
	}

	x = k;
	while (1)
	{
		path.push_back(x);
		if (x == m[x])
			break;
		sec++;
		x = m[x];
	}
	cout << sec << '\n';
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << ' ';

}

int main()
{
	FASTIO;
	cin >> n >> k;
	func();

	return 0;
}