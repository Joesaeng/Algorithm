// TEMPLATE

#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;


// ū �� ����
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

// ū �� ����
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

// ū �� ������(������ long long ����)
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

// �� ��ǥ(x,y) ������ ����
double length(double x, double y, double xx, double yy)
{
	double ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
	return ret;
}

// ����� ����(�� ���� ���� a,b,c �� ���� �� �ﰢ���� ���̸� ����)
double Heron(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	double ret = sqrt(s * (s - a) * (s - b) * (s - c));
	return ret;
}

// �Ź߲� ���� : n���� ������ �̷���� �ٰ����� �� ������ ��ǥ�� �ð�or�ݽð� �������� �־����� ��, �ٰ����� ���̸� ���ϴ� ����
double shoelace(int n, vector<pair<double, double>>& points)
{
	double ret;
	double fx = points[0].first;
	double fy = points[0].second;
	double aa = 0;
	double bb = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		double a = points[i].first * points[i + 1].second;
		double b = points[i].second * points[i + 1].first;
		aa += a;
		bb += b;
	}
	double a = points[n - 1].first * fy;
	double b = points[n - 1].second * fx;
	aa += a;
	bb += b;

	ret = abs(aa - bb) / 2;

	return ret;
}





int main()
{
    FASTIO;

    return 0;
}