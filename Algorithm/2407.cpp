// BOJ 2407 :: 조합
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
string pas[101][101];

string Sum(string left, string right)
{
	int sum = 0;
	string ret;

	while (!left.empty() || !right.empty() || sum)
	{
		if (!left.empty())
		{
			sum += left.back() - '0';
			left.pop_back();
		}
		if (!right.empty())
		{
			sum += right.back() - '0';
			right.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string combi(int n, int r)
{
	string& ret = pas[n][r];
	if (ret != "") return ret;

	// 파스칼의 삼각형 공식
	return ret = Sum(combi(n - 1, r - 1), combi(n - 1, r));
}

int main()
{
	FASTIO;
	cin >> n >> m; 
	for (int i = 0; i <= n; ++i)
		pas[i][0] = pas[i][i] = "1"; // nC0 과 nCn 은 1이다

	cout << combi(n, m);

	return 0;
}