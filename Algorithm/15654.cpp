// BOJ 15654 :: N°ú M (5)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int arr[8 + 1];
int in[8 + 1];
bool s[8 + 1];
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
		if (s[i]) continue;
		arr[cnt] = in[i];
		s[i] = true;
		func(cnt + 1);
		s[i] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> in[i];
	sort(&in[0], &in[n+1]);
	func(0);

	return 0;
}