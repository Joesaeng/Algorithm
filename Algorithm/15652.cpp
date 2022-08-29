// BOJ 15652 :: N°ú M (4)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int arr[8 + 1] = {0,};
void func(int cnt)
{
	if (cnt == m + 1)
	{
		for (int i = 1; i <= m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (arr[cnt - 1] > i) continue;
		arr[cnt] = i;
		func(cnt + 1);
	}
}

int main()
{
	FASTIO;
	cin >> n >> m;
	func(1);

	return 0;
}