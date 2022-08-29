// BOJ 15651 :: N°ú M (3)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int arr[7 + 1];
void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		arr[cnt] = i;
		func(cnt + 1);
	}
}

int main()
{
	FASTIO;
	cin >> n >> m;
	func(0);

	return 0;
}