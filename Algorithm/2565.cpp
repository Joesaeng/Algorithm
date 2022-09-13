// BOJ 2565 :: ภüฑ๊มู
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
map<int, int> m;
vector<int> vec;
vector<int> dp;
int LIS(int pos)
{
	int& ret = dp[pos];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = pos + 1; i < vec.size(); ++i)
		if (vec[pos] < vec[i])
			ret = max(ret, 1 + LIS(i));

	return ret;
}

int main()
{
	FASTIO;
	cin >> n;
	vec.resize(n + 1);
	dp = vector<int>(n + 1, -1);
	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		m.emplace(a, b);
	}
	int i = 1;
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		vec[i++] = iter->second;
	}
	int res = 0;
	for (int i = 1; i < vec.size(); ++i)
	{
		res = max(res, LIS(i));
	}
	cout << n - res;
		
	return 0;
}