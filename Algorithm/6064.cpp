// BOJ 6064 :: Ä«À× ´Þ·Â
#include <bits/stdc++.h>
using namespace std;
int m, n, x, y,t;
void func()
{
	int ans = 0;
	int nx = 0, ny = 0;
	if (x == 1 && y == 1) { cout << "1" << '\n'; return; }
	if (m < n)
	{
		while (nx != x)
		{
			nx += gcd(x, y);
			ny += gcd(x, y);
			if (ny > n)
			{
				ny -= n;
			}
			ans += gcd(x, y);
		}
		while (ny != y)
		{
			ny = ny > n ? ny - n : ny;
			ans += m;
			ny += m;
			ny = ny > n ? ny - n : ny;
			if (ny == y) break;
			if (ans > lcm(m, n))
			{
				ans = -1;
				break;
			}
		}
	}
	else if(m > n)
	{
		while (ny != y)
		{
			nx += gcd(x, y);
			ny += gcd(x, y);
			if (nx >= m)
			{
				nx -= m;
			}
			ans += gcd(x, y);
		}
		nx = nx > m ? nx - m : nx;
		while (nx != x)
		{
			nx = nx > m ? nx - m : nx;
			ans += n;
			nx += n;
			nx = nx > m ? nx - m : nx;
			if (nx == x) break;
			if (ans > lcm(m, n))
			{
				ans = -1;
				break;
			}
		}
	}
	else
	{
		if (x == y)
		{
			cout << x << '\n';
			return;
		}
		else
		{
			cout << "-1" << '\n';
			return;
		}
	}
	
	cout << ans << '\n';
}
void funca()
{
	int lim = lcm(m, n);
	int ny = 0;
	for (int i = x; i <= lim; i += m)
	{
		ny = i % n == 0 ? n : i % n;
		if (ny == y)
		{
			cout << i << '\n';
			return;
		}
	}
	cout << "-1" << '\n';
}


int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> m >> n >> x >> y;
		funca();
	}
	return 0;
}