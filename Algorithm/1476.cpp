// BOJ 1476 :: 날짜 계산
#include <bits/stdc++.h>
using namespace std;
#define MAX 7980
int max = MAX;
int e, s, m;
void func()
{
	int a = 1, b = 1, c = 1;
	for (int i = 1; i < MAX + 1; ++i)
	{
		if (a == e && b == s && c == m)
		{
			cout << i;
			break;
		}
		a++; b++; c++;
		if (a == 16)
			a = 1;
		if (b == 29)
			b = 1;
		if (c == 20)
			c = 1;
	}
}

int main()
{
	cin >> e >> s >> m;
	func();

	return 0;
}