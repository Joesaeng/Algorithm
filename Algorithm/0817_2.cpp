#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#pragma region 9613
//long long sum_gcd(vector<int> vec)
//{
//	long long res = 0;
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		if(i <= vec.size()-1)
//			for (int j = i+1; j < vec.size(); ++j)
//			{
//				res += gcd(vec[i], vec[j]);
//			}
//	}
//	return res;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,t; cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> t;
//		vector<int> v(t);
//		for (int j = 0; j < t; ++j)
//		{
//			cin >> v[j];
//		}
//		cout << sum_gcd(v) << '\n';
//	}
//	return 0;
//}
#pragma endregion: GCD합
#pragma region 17087
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; 
//	long long x; 
//	cin >> n >> x;
//	vector<long long> v(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	if (n == 1)
//	{
//		cout << abs(v[0] - x);
//	}
//	else
//	{
//		long long a = abs(v[0]-x);
//		for (int i = 1; i < v.size(); ++i)
//		{
//			a = gcd(abs(a), abs(v[i]-x));
//		}
//		cout << a;
//	}
//
//	return 0;
//}
#pragma endregion: 숨바꼭질 6
#pragma region 1373
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string a; cin >> a;
//	stack<int> s;
//	while (!a.empty())
//	{
//		if (a.length() >= 3)
//		{
//			string tmp;
//			tmp = a.substr(a.length() - 3, 3);
//			a.erase(a.length() - 3, 3);
//			if (tmp == "000")
//				s.push(0);
//			if (tmp == "001")
//				s.push(1);
//			if (tmp == "010")
//				s.push(2);
//			if (tmp == "011")
//				s.push(3);
//			if (tmp == "100")
//				s.push(4);
//			if (tmp == "101")
//				s.push(5);
//			if (tmp == "110")
//				s.push(6);
//			if (tmp == "111")
//				s.push(7);
//		}
//		else
//		{
//			int tmp = stoi(a);
//			a.erase(a.begin(), a.end());
//			switch (tmp)
//			{
//			case 0:
//				s.push(0);
//				break;
//			case 1:
//				s.push(1);
//				break;
//			case 10:
//				s.push(2);
//				break;
//			case 11:
//				s.push(3);
//				break;
//			case 100:
//				s.push(4);
//				break;
//			case 101:
//				s.push(5);
//				break;
//			case 110:
//				s.push(6);
//				break;
//			case 111:
//				s.push(7);
//				break;
//			}
//		}
//	}
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//
//
//	
//	return 0;
//}
#pragma endregion: 2진수 8진수
#pragma region 1212
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	int i = 0;
//	int len = s.length();
//	if (s[i] == '0')
//	{
//		cout << "0";
//		return 0;
//	}
//	int tmp = s[i] - '0';
//	if (tmp <= 3 && tmp >1)
//	{
//		if (tmp == 3)
//			cout << "11";
//		else
//			cout << "10";
//		++i;
//	}
//	if (tmp == 1)
//	{
//		cout << "1";
//		++i;
//	}
//	for (; i < len; ++i)
//	{
//		tmp = s[i] - '0';
//		if (tmp >= 4)
//		{
//			cout << "1";
//			tmp -= 4;
//		}
//		else
//		{
//			cout << "0";
//		}
//		if (tmp>= 2)
//		{
//			cout << "1";
//			tmp -= 2;
//		}
//		else
//		{
//			cout << "0";
//		}
//		if (tmp >= 1)
//		{
//			cout << "1";
//		}
//		else
//			cout << "0";
//	}
//	return 0;
//}
#pragma endregion: 8진수 2진수
#pragma region 2089
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	stack<int> s;
//	if (n == 0)
//	{
//		cout << "0";
//		return 0;
//	}
//	while (n != 0)
//	{
//		if (n % -2 == 0)
//		{
//			s.push(0);
//			n /= -2;
//		}
//		else
//		{
//			s.push(1);
//			n = (n-1) / -2;
//
//		}
//	}
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//	
//	return 0;
//}
#pragma endregion: -2진수
#pragma region 17103
bool b[1000001] = {true,true, };
void eratos()
{
	for (int i = 2; i < 1000001; ++i)
	{
		if (b[i])
			continue;
		for (int j = 2 * i; j < 1000001; j += i)
		{
			b[j] = true;
		}
	} // 에라토스테네스의 체
}
void gold(int x)
{
	int cnt = 0;
	for (int j = x; j >= x / 2; --j)
	{
		if (!b[j] && !b[x - j])
		{
			cnt++;
		}
	}
	cout << cnt << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	eratos();
	int n,x; cin >> n;
	for(int i =0;i<n;++i)
	{
		cin >> x;
		gold(x);
	}
	return 0;
}
#pragma endregion: 골드바흐 파티션

#pragma region 복사용
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//
//	}
//	return 0;
//}
#pragma endregion