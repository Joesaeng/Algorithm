#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 1929
	/*int M,N;
	cin >> M >> N;
	bool b[1000001]={};
	b[1] = true;
	for (int i = 2; i <= N ;++i)
	{
		if (b[i] == true)
			continue;
		for (int j = 2*i; j <= N; j+=i)
		{
			b[j] = true;
		}
	}
	for (int i = M; i <= N; ++i)
	{
		if (!b[i])
			cout << i << '\n';
	}*/
#pragma endregion: 소수 구하기 (에라토스테네스의 체)
#pragma region 4948
	/*int n = 1;
	bool b[246913] = {};
	b[1] = true;
	for (int i = 2; i <= 246913; ++i)
	{
		if (b[i] == true)
			continue;
		for (int j = 2 * i; j <= 246913; j += i)
		{
			b[j] = true;
		}
	}
	while (true)
	{
		int count =0;
		cin >> n;
		if (n == 0) break;
		for (int i = n+1; i <= 2*n; ++i)
		{
			b[i] == false ? count++ : 0;
		}
		cout << count << '\n';
		count = 0;
	}*/
#pragma endregion: 베르트랑 공준
#pragma region 9020
	bool b[10001] = {true,true,};
	for (int i = 2; i < 10001; ++i)
	{
		if (b[i])
			continue;
		for (int j = 2 * i; j < 10001; j += i)
		{
			b[j] = true;
		}
	} // 소수부터 구함
	int T, n;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		int a = 0, c=0;
		for (int j = n; j >= n/2; --j)
		{
			if (!b[j] && !b[n - j])
			{
				a = n - j;
				c = j;
			}
		}
		cout << a << ' ' << c << '\n';
	}

#pragma endregion: 골드바흐의 추측
	return 0;
}
#pragma region 복사용
#pragma endregion