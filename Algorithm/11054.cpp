// BOJ 11054 :: 가장 긴 바이토닉 부분 수열
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 + 1
int v[MAX];
int dp1[MAX];
int dp2[MAX];
int func(int x)
{
	int tmp = 0;
	for (int i = 1; i <= x; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			if (v[i] > v[j])
			{
				dp1[i] = dp1[i] > dp1[j] + 1 ? dp1[i] : dp1[j] + 1;
			}
		}
	}
	for (int i = x; i >= 1; --i)
	{
		for (int j = x; j >= i; --j)
		{
			if (v[i] > v[j])
			{
				dp2[i] = dp2[i] > dp2[j] + 1 ? dp2[i] : dp2[j] + 1;
			}
		}
	}
	for (int i = 1; i <= x; ++i)
	{
		tmp = dp1[i] + dp2[i] - 1 > tmp ? dp1[i] + dp2[i] - 1 : tmp;
	}
	

	return tmp;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i)
		dp1[i] = dp2[i] = 1;

	cout << func(n);
	return 0;
}