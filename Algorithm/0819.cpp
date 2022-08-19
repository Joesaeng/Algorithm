#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#pragma region 11727
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> v(n+1, 0);
//	v[1] = 1;
//	v[2] = 3;
//	for (int i = 3; i <= n; ++i)
//	{
//		v[i] = (v[i - 1] + v[i - 2]*2)%10007;
//	}
//	cout << v[n];
//	return 0;
//}
#pragma endregion: 2xn 타일링 2
#pragma region 9095
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n, a; cin >> n;
//	int v[11] = {};
//	v[1] = 1;
//	v[2] = 2;
//	v[3] = 4;
//	for (int i = 4; i < 11; ++i)
//	{
//		v[i] = v[i - 1] + v[i - 2] + v[i - 3];
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a;
//		cout << v[a] << '\n';
//	}
//	return 0;
//}
#pragma endregion: 1, 2, 3 더하기
#pragma region 11052
//int card(vector<int> v,vector<int> v2, int n)
//{
//	v2[1] = v[1];
//	for (int i = 2; i <= n; ++i)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			v2[i] = v2[i] > (v2[i - j] + v[j]) ? v2[i] : (v2[i - j] + v[j]);
//		}
//	}
//
//
//	return v2[n];
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> v(n + 1, 0);
//	vector<int> v2(n + 1, 0);
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	int res = card(v,v2,n);
//
//	cout << res;
//	return 0;
//}
#pragma endregion: 카드 구매하기
#pragma region 16194
//int card(vector<int> val, vector<int> dp, int n)
//{
//	dp[0] = 0;
//	dp[1] = val[1];
//	for (int i = 2; i <= n; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			dp[i] = min(dp[i],(dp[i - j] + val[j]));
//		}
//	}
//	return dp[n];
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> val(n + 1, 0);
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> val[i];
//	}
//	vector<int> dp(n + 1, 10000);
//	cout << card(val, dp, n);
//
//	return 0;
//}
#pragma endregion: 카드 구매하기 2
#pragma region 15990
//#define MOD 1000000009
//#define MAX 100000
//ll v[MAX + 1][4];
//ll func(ll x)
//{
//	for (int i = 4; i <= x; ++i)
//	{
//		v[i][1] = (v[i - 1][2] + v[i - 1][3]) % MOD;
//		v[i][2] = (v[i - 2][1] + v[i - 2][3]) % MOD;
//		v[i][3] = (v[i - 3][1] + v[i - 3][2]) % MOD;
//	}
//
//	return (v[x][1] + v[x][2] + v[x][3]) % MOD;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int a;
//	
//	v[1][1] = 1;
//	v[2][2] = 1;
//	v[3][1] = 1;
//	v[3][2] = 1;
//	v[3][3] = 1;
// 	
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a;
//		cout << func(a) << '\n';
//	}
//	return 0;
//}
#pragma endregion: 1,2,3 더하기 5
#pragma region 10844
//#define MAX 100
//#define MOD 1000000000
//ll v[MAX + 1][10];
//ll func(ll x)
//{
//	ll tmp = 0;
//	for (int i = 2; i <= x; ++i)
//	{
//		for (int j = 0; j <= 9; ++j)
//		{
//			if (j == 0)
//				v[i][0] = v[i - 1][1];
//			else if (j == 9)
//				v[i][9] = v[i - 1][8];
//			else
//				v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % MOD;
//		}
//	}
//	for (int i = 0; i <= 9; ++i)
//	{
//		tmp = (tmp + v[x][i]) % MOD;
//	}
//
//	return tmp;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	v[1][0] = 0;
//	for (int i = 1; i <= 9; ++i)
//		v[1][i] = 1;
//	cout << func(n);
//	return 0;
//}
#pragma endregion: 쉬운 계단 수
#pragma region 2193
//#define MAX 90
//ll v[MAX + 1][2] = {};
//ll func(int x)
//{
//	for (int i = 4; i <= x; ++i)
//	{
//		v[i][0] = v[i - 1][1] +v[i - 1][0];
//		v[i][1] = v[i - 1][0];
//	}
//	return v[x][0] + v[x][1];
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	v[1][0] = 0;
//	v[1][1] = 1;
//	v[2][0] = 1;
//	v[2][1] = 0;
//	v[3][0] = 1;
//	v[3][1] = 1;
//	cout << func(n);
//	
//	return 0;
//}
#pragma endregion: 이친수
#pragma region 11053
//#define MAX 1000
//int v[MAX+1];
//int dp[MAX + 1];
//int func(int x)
//{
//	int tmp = 0;
//	for (int i = 1; i <= x; ++i)
//	{
//		dp[i] = 1;
//		for (int j = i - 1; j >= 1; --j)
//		{
//			if (v[i] > v[j])
//			{
//				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
//			}
//		}
//		tmp = dp[i] > tmp ? dp[i] : tmp;
//	}
//
//	
//	return tmp;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> v[i];
//	}
//		
//	cout << func(n);
//	return 0;
//}
#pragma endregion: 가장 긴 증가하는 부분 수열
#pragma region 14002
//#define MAX 1000
//int v[MAX + 1];
//int dp[MAX + 1];
//stack<int> stk;
//int func(int x)
//{
//	int tmp = 0;
//	int s = 0;
//	for (int i = 1; i <= x; ++i)
//	{
//		dp[i] = 1;
//		for (int j = i - 1; j >= 1; --j)
//		{
//			if (v[i] > v[j])
//			{
//				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
//			}
//		}
//		if (dp[i] > tmp)
//		{
//			tmp = dp[i];
//			s = i;
//		}
//	}
//	
//	int t = 0;
//	for (int i = s; i >= 1; --i)
//	{
//		if (dp[s]-t == dp[i])
//		{
//			stk.push(v[i]);
//			++t;
//		}
//	}
//
//	return tmp;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> v[i];
//	}
//
//	cout << func(n) << '\n';
//	while (!stk.empty())
//	{
//		cout << stk.top() << " ";
//		stk.pop();
//	}
//	return 0;
//}
#pragma endregion 가장 긴 증가하는 부분 수열 4



#pragma region 복사용
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//
//	}
//	return 0;
//}
#pragma endregion