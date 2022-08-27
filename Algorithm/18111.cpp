// BOJ 18111 :: 마인크래프트
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, b;
int v[500][500];
int f = 0, s = 0;
int res = 2100000000;
int h = 0;
void func()
{
	for(int j = 0; j <= 256; ++j)
	{
		f = 0; s = 0;
		int x = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int l = 0; l < m; ++l)
			{
				x = v[i][l] - j;
				if (x > 0)
				{
					f += x;
				}
				else if (x < 0)
				{
					s += (-x);
				}
			}
		}
		if (f + b >= s)
		{
			int t = f * 2 + s;
			if (t <= res)
			{
				res = t;
				h = j;
			}
		}
	}

	cout << res << " " << h;
}

int main()
{
	FASTIO;
	cin >> n >> m >> b;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		cin >> v[i][j];
	}
	func();

	return 0;
}