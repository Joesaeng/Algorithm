#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 1712
	/*int a =0, b=0, c=0, d=0, i=0; 
	cin >> a >> b >> c;
	while ((a + b * i - c * i) >= 0 && c > b)
	{
		if (a / (c - b) > 1 && i == 0)
		{
			i += (a / (c - b));
		}
		else
			++i;
	}
	if (c <= b) i = -1;
	cout << i;*/
#pragma endregion: 손익분기점
#pragma region 2292
	/*int N = 0, a = 1, n = 0;
	cin >> N;
	while (N > a && N != 1)
	{
		a += 6 * n++;
	}
	N == 1 ? cout << 1 : cout << n;*/
#pragma endregion: 벌집
#pragma region 1193
	/*int X = 0, i = 1;
	cin >> X;
	while (X > i)
	{
		X -= i;
		i++;
	}
	if (i % 2 == 1)
		cout << i + 1 - X << '/' << X << endl;
	else
		cout << X << '/' << i + 1 - X << endl;*/
#pragma endregion: 분수찾기
#pragma region 2869
	/*int A, B, V; 
	double day = 0.f;
	cin >> A >> B >> V;
	if (A == V)
		cout << 1;
	else
	{
		day = ceil(double(V - A) / double(A - B));
		cout << (int)day + 1;
	}*/
		

	
#pragma endregion: 달팽이는 올라가고 싶다
#pragma region 10250
	int T, H, W, N;
	cin >> T;
	vector<int> yV;
	vector<int> xV;
	for (int i = 0; i < T; ++i)
	{
		cin >> H >> W >> N;
		int y = 0;
		double x = 0;
		if (N < H)
		{
			y = N;
			x = 01;
		}
		else
		{
			if (N % H == 0)
				y = H;
			else
				y = N % H;
			x = ceil((double)N / (double)H);
		}
		yV.push_back(y);
		xV.push_back(x);
	}
	for (int i = 0; i < T; ++i)
	{
		if (xV[i] < 10)
			cout << yV[i] << '0' << (int)xV[i] << '\n';
		else
			cout << yV[i] << (int)xV[i] << '\n';
	}
#pragma endregion: ACM 호텔
	return 0;
}



#pragma region 복사용
#pragma endregion