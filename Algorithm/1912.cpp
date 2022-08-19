// BOJ 1912 :: ¿¬¼ÓÇÕ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100001
ll v[MAX];
ll dp[MAX];

ll func(int x)
{
	ll tmp = dp[0];
	for (int i = 1; i < x; ++i)
	{
		dp[i] = v[i] > dp[i - 1] + v[i] ? v[i] : dp[i - 1] + v[i];
		tmp = dp[i] > tmp ? dp[i] : tmp;
	}
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		dp[i] = v[i];
	}
	cout << func(n);
	return 0;
}