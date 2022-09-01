// BOJ 10819 :: 차이를 최대로
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<int> vec(9);
int arr[9];
bool b[9];
int n;
int ans;
void func(int cnt)
{
	if (cnt == n + 1)
	{
		int sum = 0;
		for (int i = 1; i < n; ++i)
		{
			sum += abs(arr[i] - arr[i + 1]);
		}
		ans = max(ans, sum);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (b[i]) continue;
		b[i] = true;
		arr[cnt] = vec[i];
		func(cnt + 1);
		b[i] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1;i <= n; ++i)
		cin >> vec[i];
	func(1);
	cout << ans;

	return 0;
}