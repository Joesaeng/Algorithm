#include <bits/stdc++.h>

// Å« ¼ö µ¡¼À
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

// Å« ¼ö »¬¼À
string subtraction(string left, string right)
{
	bool b = false;
	ll res = 0, leftl = left.length(), rightl = right.length();
	string s;

	for (ll i = 0; i < leftl || i < rightl; ++i)
	{
		if (i < leftl)
		{
			res += left[leftl - i - 1] - '0';
			if (b) { res--; b = false; }
		}
		if (i < rightl)
			res -= right[rightl - i - 1] - '0';

		if (res < 0)
		{
			res = 10 - abs(res);
			b = true;
		}
		s += res + '0';
		res = 0;
	}
	if (s.back() == '0' && s.length() > 1) s.pop_back();
	reverse(s.begin(), s.end());

	return s;
}

// Å« ¼ö ³ª´°¼À(Á¦¼ö´Â long long ÀÌÇÏ)
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
	int i = 0;
	for (; i < s.length(); ++i)
		if (s[i] != '0') break;
	s = s.substr(i, s.length());
	return s;
}