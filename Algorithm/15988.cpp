// BOJ 15988 :: 1,2,3 ¥ı«œ±‚ 3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000001
#define MOD 1000000009
ll v[MAX];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a; cin >> n;
	v[1] = 1;
	v[2] = 2;
	v[3] = 4;
	for (int i = 4; i < MAX; ++i)
	{
		v[i] = (v[i - 1] + v[i - 2] + v[i - 3])%MOD;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cout << v[a] << '\n';
	}
	return 0;
}