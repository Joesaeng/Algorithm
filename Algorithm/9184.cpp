// BOJ 9184 :: 신나는 함수 실행
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int a, b, c;
int dp[102][102][102];
int DP(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	int& ret = dp[a][b][c];
	if (ret != 0)
		return ret;

	if (a > 20 || b > 20 || c > 20)
		return ret = DP(20, 20, 20);

	if (a < b && b < c)
		return ret = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
	
	return ret = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);

}
int main()
{
	FASTIO;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		int res = DP(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << res << '\n';
	}

	return 0;
}