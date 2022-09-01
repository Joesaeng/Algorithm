// BOJ 10974 :: 모든 순열
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
vector<int> vec(9);
bool b[9];
void func(int cnt)
{
	if (cnt == n+1)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (b[i]) continue;
		b[i] = true;
		vec[cnt] = i;
		func(cnt + 1);
		b[i] = false;
	}
	
}

int main()
{
	FASTIO;
	cin >> n;
	func(1);

	return 0;
}