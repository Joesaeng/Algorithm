// BOJ 13398 : ¿¬¼ÓÇÕ 2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100000 + 1
int v[MAX];
ll dpl[MAX];
ll dpr[MAX];
ll func(ll x)
{
	ll tmp = dpl[1];

	for (int i = 2; i <= x; ++i)
	{
		dpl[i] = v[i] > dpl[i - 1] + v[i] ? v[i] : dpl[i - 1] + v[i];
		tmp = dpl[i] > tmp ? dpl[i] : tmp;
	}
	for (int i = x-1; i >= 1; --i)
	{
		dpr[i] = v[i] > dpr[i + 1] + v[i] ? v[i] : dpr[i + 1] + v[i];
	}
	for (int i = 2; i <= x-1; ++i)
	{
		tmp = max(tmp, dpl[i - 1] + dpr[i + 1]);
	}

	return tmp;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		dpl[i] = v[i];
		dpr[i] = v[i];
	}

	cout << func(n);
	return 0;
}