#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 3003
	//int bKing = 1, bQueen = 1, bRook = 2, bBishop = 2, bKnight = 2, bPawn = 8;
	//int wKing = 0, wQueen = 0, wRook = 0, wBishop = 0, wKnight = 0, wPawn = 0;
	//cin >> wKing >> wQueen >> wRook >> wBishop >> wKnight >> wPawn;
	//cout << bKing - wKing <<' '
	//	<< bQueen - wQueen << ' '
	//	<< bRook - wRook << ' '
	//	<< bBishop - wBishop << ' '
	//	<< bKnight - wKnight << ' '
	//	<< bPawn - wPawn;
#pragma endregion: 킹,퀸,룩,비숍,나이트,폰
#pragma region 25304
	/*int x = 0, N;
	cin >> x;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		x -= a * b;
	}
	x == 0 ? cout << "Yes" : cout << "No";*/

#pragma endregion: 영수증
#pragma region 2775
	/*int T, k, n;
	vector<int> ans;
	cin >> T;
	for (int l = 0; l < T; ++l)
	{
		int x[15][15] = {};
		cin >> k >> n;
		for (int i = 0; i <= k; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == 0)
					x[i][j] = j;
				else if (j == 1)
					x[i][j] = 1;
				else
					x[i][j] = x[i - 1][j] + x[i][j - 1];
			}
		}
		ans.push_back(x[k][n]);
	}
	for (auto i : ans)
		cout << i << '\n';*/

#pragma endregion: 부녀회장이 될테야
#pragma region 2839
		/*int N, k = 0;
		int i = 0, j = 0;
		cin >> N;
		i = N / 5;
		k = N;
		if (N % 5 == 0) { cout << N / 5;}
		else if (N % 5 == 3) { cout << N / 5 + 1;}
		else
			while (true)
			{
				if (k % 5 != 3)
					i > 0 && k / 5 > 0 ? --i : 0;

				j = (N - i * 5) / 3;
				k = i * 5 + j * 3;


				if (k == N)
				{
					cout << i + j;
					break;
				}
				else if (k < 3 || (i == 0 && N - k < 3))
				{
					cout << -1;
					break;
				}
			}*/
#pragma endregion: 설탕 배달
#pragma region 10757
			//int x[10001]={}, y[10001]={};
			//char c[10002]={};
			//string a, b, t;
			//cin >> a >> b;
			//if (b.size() > a.size()) { t = a; a = b; b = t; } // b의 길이가 a보다 길경우 순서를 바꿈
			//for (int i = 0; i < a.size(); ++i)
			//{
			//	x[i + 1] = a[i] - '0'; // 입력받은 문자열을 int 배열로 변환
			//}
			//for (int i = 0; i < b.size(); ++i)
			//{
			//	y[i + 1 + (a.size()-b.size())] = b[i] - '0'; // 두 문자열의 자릿수를 맞추는 작업
			//}
			//for (int i = a.size(); i > 0; --i) // 0번은 자릿수올림을 위해 비워둠
			//{
			//	if(x[i] + y[i] +c[i] <10)
			//		c[i] += x[i] + y[i];
			//	else
			//	{
			//		c[i - 1] += 1; // 자릿수올림
			//		c[i] += x[i] + y[i] - 10;
			//	}
			//}
			//if (c[0] != 0) // 첫자리가 올라갔을경우 0번부터 출력
			//{
			//	for (int i = 0; i < a.size() + 1; ++i)
			//	{
			//		cout << (int)c[i];
			//	}
			//}
			//else
			//{
			//	for (int i = 1; i < a.size() + 1; ++i)
			//	{
			//		cout << (int)c[i];
			//	}
			//}
#pragma endregion: 큰 수 A+B
#pragma region 1978
	/*int N;
	cin >> N;
	int a[100]={};
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N ;++i)
	{
		for (int j = 2; j <= a[i]; ++j)
		{
			if (a[i] % j == 0)
			{
				if (a[i] != j)
				{
					break;
				}
				else
				{
					ans++;
				}

			}
		}
	}
	cout << ans;*/
#pragma endregion: 소수 찾기
#pragma region 2581
	/*int M, N,sum=0,min=0;
	bool b = false;
	cin >> M >> N;
	for (int i = M; i <= N; ++i)
	{
		for (int j = 2; j <= i; ++j)
		{
			if (i % j == 0)
			{
				if (i != j)
				{
					break;
				}
				else if (b == false)
				{
					sum += i;
					min = i;
					b = true;
				}
				else
					sum += i;
			}
		}
	}
	if (b)
		cout << sum << '\n' << min;
	else
		cout << -1;*/
#pragma endregion: 소수
#pragma region 11653
		//int N,i=2;
		//cin >> N;
		//while (N > 1)
		//{
		//	if (N % i == 0)
		//	{
		//		cout << i << '\n';
		//		N /= i;
		//	}
		//	else
		//	{
		//		++i;
		//	}
		//}
#pragma endregion: 소인수분해
	return 0;
}


#pragma region 복사용
#pragma endregion
