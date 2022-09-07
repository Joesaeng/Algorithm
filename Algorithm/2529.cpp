// BOJ 2529 :: ∫ŒµÓ»£
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll MIN = 10000000000, MAX = 0;
int n;
int v[10];
char k[9];
bool b[10];
string sMin, sMax;
void DFS(int cnt)
{
	char c = k[cnt];
	if (cnt == n)
	{
		string s;
		for (int i = 0; i <= n; ++i)
				s += (char)v[i] + '0';
		
		ll x = stoll(s);
		if (x < MIN)
		{
			string t;
			MIN = x;
			if (s[0] == '0') t += '0';
			t += s;
			sMin = s;
		}
		if (x > MAX)
		{
			string t;
			MAX = x;
			if (s[0] == '0') t += '0';
			t += s;
			sMax = s;
		}
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (b[i]) continue;
		if (c == '<')
		{
			if (v[cnt] < i)
			{
				b[i] = true;
				v[cnt + 1] = i;
				DFS(cnt + 1);
				b[i] = false;
			}
		}
		else
		{
			if (v[cnt] > i)
			{
				b[i] = true;
				v[cnt + 1] = i;
				DFS(cnt + 1);
				b[i] = false;
			}
		}
	}
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> k[i];
	for (int i = 0; i <= 9; ++i)
	{
		b[i] = true;
		v[0] = i;
		DFS(0);
		b[i] = false;
	}
	cout << sMax << '\n' << sMin;

	return 0;
}