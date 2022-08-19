#include <bits/stdc++.h>
using namespace std;

#pragma region 11005
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,b; cin >> n >> b;
//	stack<char> s;
//	if (n == 0)
//	{
//		cout << "0";
//		return 0;
//	}
//	while (n != 0)
//	{
//		if (n % b == 0)
//		{
//			s.push('0');
//			n /= b;
//		}
//		else
//		{
//			if (n % b >= 10 && n % b <= 35)
//			{
//				s.push(char(n % b) + 55);
//			}
//			else
//			{
//				s.push(char(n % b) + '0');
//			}
//			n /= b;
//		}
//	}
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//	return 0;
//}
#pragma endregion: 진법 변환 2
#pragma region 2745
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string n;
//	int b;
//	int j=0;
//	int res = 0;
//	cin >> n >> b;
//	for (int i = n.length() - 1; i >= 0; --i)
//	{
//		if (n[i] >= '0' && n[i] <= '9')
//		{
//			res += int(n[i] - '0') * pow(b,j++);
//		}
//		else
//		{
//			res += int(n[i] - 55) * pow(b,j++);
//		}
//	}
//	cout << res;
//	return 0;
//}
#pragma endregion: 진법 변환
#pragma region 11576
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int a,b; cin >> a>>b;
//	int m; cin >> m;
//	int res = 0;
//	vector<int> x(m);
//	stack<int> s;
//	for (int i = 0; i < m; ++i)
//		cin >> x[i];
//	for (int i = 0; i < m; ++i)
//	{
//		res += x[i] * pow(a,(m - i - 1));
//	}
//	while (res != 0)
//	{
//		s.push(res % b);
//		res /= b;
//	}
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		s.pop();
//	}
//	return 0;
//}
#pragma endregion: Base Conversion
#pragma region 1463
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n+1,0);
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	v[2] = 1; // n == 2 ? v[2] = 2-1(1회)
	v[3] = 1; // n == 3 ? v[3] = 3/3(1회)
	for (int i = 4; i <= n; ++i)
	{
		if (i % 2 != 0 && i % 3 != 0)
			v[i] = 1 + v[i - 1]; // ex) i == 5 ? v[5] = 1(1회) + v[5-1](v[4]= 1 + v[4]= 4 / 2 - 1 ) == 3회
		else if (i % 2 == 0 && i % 3 == 0)
			v[i] = min(1 + v[i / 3], 1 + v[i / 2]); // ex) i == 12 ? min(1 + v[4](2회), 1 + v[6](2회)) == 3회
		else if (i % 2 == 0)
			v[i] = min(1 + v[i / 2], 1 + v[i - 1]); // ex) i == 10 ? min(1 + v[5](3회), 1 + v[9](2회)) == 3회
		else if (i % 3 == 0)
			v[i] = min(1 + v[i / 3], 1 + v[i - 1]); // ex) i == 21 ? min(1 + v[7](3회), 1 + v[20](4회)) == 4회
	}												//  v[20] == min(1 + v[10](3회), 1+ v[19](4회)) == 4회
													//  v[19] == 1 + v[18](3회) == 4회
													//  v[18] == min(1 + v[6](2회),1 + v[9](2회)) == 3회 . . .  이런 식으로 풀이가 된다.
	cout << v[n];

	return 0;
}
#pragma endregion: 1로 만들기

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