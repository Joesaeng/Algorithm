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
#pragma endregion: ���� ��ȯ 2
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
#pragma endregion: ���� ��ȯ
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
	v[2] = 1; // n == 2 ? v[2] = 2-1(1ȸ)
	v[3] = 1; // n == 3 ? v[3] = 3/3(1ȸ)
	for (int i = 4; i <= n; ++i)
	{
		if (i % 2 != 0 && i % 3 != 0)
			v[i] = 1 + v[i - 1]; // ex) i == 5 ? v[5] = 1(1ȸ) + v[5-1](v[4]= 1 + v[4]= 4 / 2 - 1 ) == 3ȸ
		else if (i % 2 == 0 && i % 3 == 0)
			v[i] = min(1 + v[i / 3], 1 + v[i / 2]); // ex) i == 12 ? min(1 + v[4](2ȸ), 1 + v[6](2ȸ)) == 3ȸ
		else if (i % 2 == 0)
			v[i] = min(1 + v[i / 2], 1 + v[i - 1]); // ex) i == 10 ? min(1 + v[5](3ȸ), 1 + v[9](2ȸ)) == 3ȸ
		else if (i % 3 == 0)
			v[i] = min(1 + v[i / 3], 1 + v[i - 1]); // ex) i == 21 ? min(1 + v[7](3ȸ), 1 + v[20](4ȸ)) == 4ȸ
	}												//  v[20] == min(1 + v[10](3ȸ), 1+ v[19](4ȸ)) == 4ȸ
													//  v[19] == 1 + v[18](3ȸ) == 4ȸ
													//  v[18] == min(1 + v[6](2ȸ),1 + v[9](2ȸ)) == 3ȸ . . .  �̷� ������ Ǯ�̰� �ȴ�.
	cout << v[n];

	return 0;
}
#pragma endregion: 1�� �����

#pragma region �����
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