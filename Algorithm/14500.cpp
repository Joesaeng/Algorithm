// BOJ 14500 :: 테트로미노
#include <bits/stdc++.h>
using namespace std;
#define MAX 500 + 10
int n, m;
int v[MAX][MAX];
int maxa = 0;
int BIG(int a, int b)
{
	if (a > b) return a; else return b;
}
void func()
{
	for (int i = 3; i < n + 3; ++i)
	{
		for (int j = 3; j < m + 3; ++j)
		{
			maxa = BIG(maxa,v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3]);
			maxa = BIG(maxa,v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i][j+2] + v[i+1][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+2][j] + v[i+1][j-1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j-1] + v[i+1][j] + v[i+1][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+2][j] + v[i+1][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+1][j+1] + v[i+2][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j-1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+1][j-1] + v[i+2][j-1]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i+1][j+1] + v[i+1][j+2]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+2][j] + v[i+2][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i][j+1] + v[i][j+2]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i+1][j+1] + v[i+2][j+1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+1][j-1] + v[i+1][j-2]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+2][j] + v[i+2][j-1]);
			maxa = BIG(maxa,v[i][j] + v[i+1][j] + v[i+1][j+1] + v[i+1][j+2]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i+1][j] + v[i+2][j]);
			maxa = BIG(maxa,v[i][j] + v[i][j+1] + v[i][j+2] + v[i+1][j+2]);
		}
	}
	cout << maxa;
}


int main()
{
	memset(v, 0, sizeof(v));
	cin >> n >> m;
	for (int i = 3; i < n + 3; ++i)
	{
		for (int j = 3; j < m + 3; ++j)
		{
			cin >> v[i][j];
		}
	}

	func();


	return 0;
}