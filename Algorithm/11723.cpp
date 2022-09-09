// BOJ 11723 :: 집합(비트마스크)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using uint = unsigned int;

int main()
{
	FASTIO;
	uint s = 0;
	uint x;
	string str;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> str;
		switch (str[1])
		{
		case 'd':
			cin >> x;
			s |= (1 << x); // | (OR)
			break;
		case 'e':
			cin >> x;
			s &= ~(1 << x); // & (AND)
			break;
		case 'h':
			cin >> x;
			if (s & (1 << x)) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		case 'o':
			cin >> x;
			s ^= (1 << x); // ^ (XOR)
			break;
		case 'l':
			s = (1 << 21) - 1;
			break;
		case 'm':
			s = 0;
			break;
		}
	}

	return 0;
}