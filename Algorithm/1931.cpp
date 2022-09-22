// BOJ 1931 :: 회의실 배정
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, ans;
vector<pair<int,int>> vec;
int main()
{
	FASTIO;
	cin >> n;
	int a, b;
	vec = vector<pair<int,int>>(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].second >> vec[i].first;
	}
	sort(vec.begin(), vec.end());
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		if (t <= vec[i].second)
		{
			ans++;
			t = vec[i].first;
		}
	}
	cout << ans;
    return 0;
}