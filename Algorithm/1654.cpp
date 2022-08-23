// BOJ 1654 :: 랜선 자르기
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define KMAX 10000 + 1
ll v[KMAX] = {0,};
ll MAX = 0;
ll MIN = 0;
ll MID = 0;
ll res;
void cut(int n,int k)
{
	while (MIN <= MAX)
	{
		ll cnt = 0;
		MID = (MAX + MIN) / 2;
		if (MID == 0)
		{
			res = 1;
			break;
		}
		for (int i = 1; i <= k; ++i)
		{
			cnt += v[i] / MID;
		}
		if (cnt < n)
		{
			MAX = MID - 1;
			res = MID - 1;
		}
		else
		{
			MIN = MID + 1;
		}
	}
}
int main()
{
	int k, n; cin >> k >> n;
	for (int i = 1; i <= k; ++i)
	{
		cin >> v[i];
		MAX = max(MAX, v[i]);
	}
	cut(n, k);
	cout << res;

	return 0;
}