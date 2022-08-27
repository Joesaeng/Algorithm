// BOJ 4153 :: Á÷°¢»ï°¢Çü
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a, b, c;
void func()
{
	ll v[3] = { a * a,b * b,c * c };
	sort(&v[0], &v[3]);
	if (v[0] + v[1] == v[2])
		cout << "right" << '\n';
	else
		cout << "wrong" << '\n';
}

int main()
{
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;
		func();
	}

	return 0;
}