// BOJ 16940 :: BFS 스페셜 저지
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100001
using namespace std;
int n, a, b;
vector<int> vec[MAX];
vector<int> tmp(MAX);
int order[MAX];
bool comp(const int& a, const int& b)
{
	return order[a] < order[b];
}
int BFS()
{
	int num = 1;
	if (tmp[num] != 1)
	{
		return 0;
	}
	num++;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : vec[x])
		{
			if (num == n + 1) return 1;
			if (tmp[num] == next)
			{
				q.push(next);
				num++;
			}
		}
	}
	if (num == n + 1) return 1;
	else return 0;
}
int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		tmp[i] = a;
		order[a] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(vec[i].begin(), vec[i].end(), comp);
	}
	cout << BFS();
	return 0;
}