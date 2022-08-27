// BOJ 11050 :: 이항 계수 1
#include <bits/stdc++.h>
using namespace std;
int func(int x)
{
	int ans = 1;
	if (x != 0)
		for (int i = x; i >= 1; i--)
			ans *= i;


	return ans;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << func(a) / (func(b) * func(a - b));


	return 0;
}