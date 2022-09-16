// BOJ 1271 :: 엄청난 부자2 // 파이썬으로 품 포기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
string n, m, sMod;
ll mod;
ll cnt;
bool check(string& a, string& b) 
{
	if (a.length() > b.length()) return true;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] > b[i])
			return true;
	}
	return false;
}
string subtraction(string left, string right)
{


	return
}

string ll_div(string str, ll div)
{
	ll res = 0;
	string s;

	for (ll i = 0; i < str.length(); ++i)
	{
		res = (res * 10) + str[i] - '0';
		s += (res / div) + '0';
		res %= div;
	}
	mod = res;
	return s;
}
int main()
{
	FASTIO;
	cin >> n >> m;
	if (m.length() < 19)
	{
		string x = ll_div(n, stoll(m));
		int i = 0;
		for (; i < x.length(); ++i)
			if (x[i] != '0') break;
		cout << x.substr(i,x.length()) << '\n' << mod;
	}
	else 
	{
		cout << div(n, m) << '\n' << sMod;
	}

	return 0;
}