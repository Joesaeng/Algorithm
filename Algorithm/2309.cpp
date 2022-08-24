// BOJ 2309 :: ¿œ∞ˆ ≥≠¿Ô¿Ã
#include <bits/stdc++.h>
using namespace std;
int v[9];
int sum = 0;;
void func()
{
	for (int i = 0; i < 9; ++i)
	{
		int tmp = sum;
		tmp -= v[i];
		for (int j = 0; j < 9; ++j)
		{
			if (i == j)
				continue;
			if (tmp - v[j] == 100)
			{
				v[i] = v[j] = 0;
				return;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	func();
	sort(&v[0], &v[9]);
	for (int i = 0; i < 9; ++i)
	{
		if (v[i] != 0)
			cout << v[i] << '\n';
	}
	

	return 0;
}