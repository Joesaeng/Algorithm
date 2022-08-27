// BOJ 2805 :: 나무 자르기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int n, m;
ll v[1000001];
ll MIN = 0, MAX = 0, MID;
void cut()
{
	while (MIN <= MAX)
	{
		ll sum = 0;
		ll x = 0;
		MID = (MAX + MIN) / 2;
		for (int i = 1; i <= n; ++i)
		{
			x = v[i] - MID;
			if (x > 0)
				sum += x;
		}
		if (sum < m)
		{
			MAX = MID - 1;
		}
		else
		{
			MIN = MID + 1;
			
		}
	}
	cout << MAX;
}
int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		MAX = max(MAX, v[i]);
	}
	cut();

	return 0;
}