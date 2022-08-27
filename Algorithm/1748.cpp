// BOJ 1748 :: 수 이어 쓰기 1
#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;
using ll = long long;
int n;
ll ans = 0;
void func()
{
	int j = 0;
	int l = 1;
	for (int i = 9; i <= MAX; i = (i * 10) + 9)
	{
		if (n > i)
		{
			ans += (i - j) * l++;
		}
		else
		{
			ans += (n - j) * l;
			break;
		}
		j = i;
	}
	if (n == 100000000)
		ans += (n - j) * l;
	cout << ans;
}

int main()
{
	cin >> n;
	func();
	return 0;
}