// BOJ 15829 :: Hashing
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = unsigned long long;

#define R 31
#define M 1234567891

ll sum = 0;
ll x;
int n;
string s;
ll r = 1;

ll func()
{
	for (int i = 0; i < n; ++i)
	{
		x = s[i] - 'a' + 1;
		int xr = (x * r) % M;
		sum += xr;
		r *= R;
		r %= M;
	}


	return sum % M;
}

int main()
{
	FASTIO;
	cin >> n;
	cin >> s;
	cout << func();

	return 0;
}