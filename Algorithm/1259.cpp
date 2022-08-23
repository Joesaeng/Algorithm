// BOJ 1259 :: Æç¸°µå·Ò¼ö
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (true)
	{
		cin >> s;
		bool b = true;
		if (s[0] == '0')
			break;
		for (int i = 0; i < s.length() / 2; ++i)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				b = false;
				break;
			}
		}
		if (b)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}


	return 0;
}