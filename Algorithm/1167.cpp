// BOJ 1167 :: 트리의 지름
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, a, b, c;
vector<pair<int, int>> vec[100001];
int ans = 0;
void func(int vt)
{
	
}
void input(int num)
{
	cin >> b;
	if (b == -1) return;
	cin >> c;
	vec[num].push_back({ b,c });
	input(num);
}
int main()
{
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		input(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		func(i);
	}
	cout << ans;
	return 0;
}