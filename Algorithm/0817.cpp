#include <bits/stdc++.h>
using namespace std;

#pragma region 17298
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	
//	vector<int> vec(n);
//	vector<int> nge(n, -1);
//	stack<int> stk;
//	for (int i = 0; i < vec.size(); ++i)
//		cin >> vec[i];
//
//	for (int i = vec.size() - 1; i >= 0; --i)
//	{
//		while (!stk.empty() && stk.top() <= vec[i])
//		{
//			stk.pop();
//		}
//		if (!stk.empty()) nge[i] = stk.top();
//
//		stk.push(vec[i]);
//	}
//	for (int a : nge)
//		cout << a << " ";
//
//
//	return 0;
//}
#pragma endregion: 오큰수
#pragma region 17299
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> a(n);
//	vector<int> res(n, -1);
//	vector<pair<int, int>> f(1000001);
//	stack<pair<int,int>> stk;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		f[a[i]].second++;
//	}
//	for (int i = a.size() - 1; i >= 0; --i)
//	{
//		while (!stk.empty() && stk.top().second <= f[a[i]].second)
//		{
//			stk.pop();
//		}
//		if (!stk.empty()) res[i] = stk.top().first;
//
//		stk.push(pair(a[i],f[a[i]].second));
//	}
//	for (int i : res)
//		cout << i << " ";
//	return 0;
//}
#pragma endregion: 오등큰수
#pragma region 1935
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	string s; cin >> s;
//	stack<double> stk;
//	vector<int> v(n);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	for (int i = 0; i < s.length(); ++i)
//	{
//		if (s[i] >= 'A' && s[i] <= 'Z')
//		{
//			stk.push(v[s[i] - 'A']);
//		}
//		else
//		{
//			if (!stk.empty())
//			{
//				double tmp = stk.top();
//				stk.pop();
//				if (s[i] == '+')
//				{
//					tmp = stk.top() + tmp;
//				}
//				else if (s[i] == '-')
//				{
//					tmp = stk.top() - tmp;
//				}
//				else if (s[i] == '*')
//				{
//					tmp = stk.top() * tmp;
//				}
//				else if (s[i] == '/')
//				{
//					tmp = stk.top() / tmp;
//				}
//				stk.pop();
//				stk.push(tmp);
//			}
//		}
//	}
//	cout << fixed;
//	cout.precision(2);
//	cout << stk.top();
//
//	return 0;
//}
#pragma endregion: 후위 표기식2
#pragma region 1918
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string x; cin >> x;
//	string ans;
//	stack<char> s;
//	for (int i = 0; i < x.length(); ++i)
//	{
//		if (x[i] >= 'A' && x[i] <= 'Z')
//		{
//			ans += x[i];
//		}
//		else
//		{
//			if (x[i] == '(')
//			{
//				s.push(x[i]);
//			}
//			else if (x[i] == '*' || x[i] == '/')
//			{
//				while (!s.empty() && (s.top() == '*' || s.top() == '/'))
//				{
//					ans += s.top();
//					s.pop();
//				}
//				s.push(x[i]);
//			}
//			else if (x[i] == '+' || x[i] == '-')
//			{
//				while (!s.empty() && s.top() != '(')
//				{
//					ans += s.top();
//					s.pop();
//				}
//				s.push(x[i]);
//			}
//			else if (x[i] == ')')
//			{
//				while (!s.empty() && s.top() != '(')
//				{
//					ans += s.top();
//					s.pop();
//				}
//				s.pop();
//			}
//		}
//	}
//	while (!s.empty())
//	{
//		ans += s.top();
//		s.pop();
//	}
//	cout << ans;
//	return 0;
//}
#pragma endregion: 후위 표기식
#pragma region 10808
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string n; cin >> n;
//	int x[26] = {};
//	for (int i = 0; i < n.length(); ++i)
//	{
//		x[n[i] - 'a']++;
//	}
//	for (int a : x)
//		cout << a << " ";
//	return 0;
//}
#pragma endregion: 알파벳 개수
#pragma region 10809
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	vector<int> v(26, -1);
//	for (int i = 0; i < s.length(); ++i)
//	{
//		if(v[s[i] - 'a'] == -1)
//			v[s[i] - 'a'] = i;
//	}
//	for (int a : v)
//		cout << a << " ";
//	return 0;
//}
#pragma endregion: 알파벳 찾기
#pragma region 10820
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; 
//	while (true)
//	{
//		int A = 0, a = 0, num = 0, spa = 0;
//		getline(cin, s);
//		if (s.length() == 0)
//			break;
//		for (int i = 0; i < s.length(); ++i)
//		{
//			if (s[i] >= 'A' && s[i] <= 'Z')
//				++A;
//			else if (s[i] >= 'a' && s[i] <= 'z')
//				++a;
//			else if (s[i] == ' ')
//				++spa;
//			else if (s[i] >= '0' && s[i] <= '9')
//				++num;
//		}
//		cout << a << " " << A << " " << num << " " << spa << '\n';
//	}
//		
//	
//	return 0;
//}
#pragma endregion: 문자열 분석
#pragma region 2743
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	cout << s.length();
//	return 0;
//}
#pragma endregion: 단어 길이 재기
#pragma region 11655
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; getline(cin, s);
//	for (int i = 0; i < s.length(); ++i)
//	{
//		if (s[i] >= 'A' && s[i] <= 'Z')
//		{
//			if (s[i] + 13 > 'Z')
//				cout << char(s[i] - 13);
//			else
//				cout << char(s[i] + 13);
//		}
//		else if (s[i] >= 'a' && s[i] <= 'z')
//		{
//			if (s[i] + 13 > 'z')
//				cout << char(s[i] - 13);
//			else
//				cout << char(s[i] + 13);
//		}
//		else
//			cout << s[i];
//	}
//	return 0;
//}
#pragma endregion: ROT13
#pragma region 10824
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string a, b, c, d; cin >> a >> b >> c >> d;
//	a += b; c += d;
//	long long res = stoll(a) + stoll(c);
//	cout << res;
//	return 0;
//}
#pragma endregion: 네 수
#pragma region 11656
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	vector<string> v(s.length());
//	for (int i = 0; i < s.length(); ++i)
//	{
//		v[i] = s.substr(i, s.length() - i);
//	}
//	sort(v.begin(),v.end());
//	for (auto a : v)
//		cout << a << '\n';
//	return 0;
//}
#pragma endregion: 접미사 배열
#pragma region 10430
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int a, b, c; cin >> a >> b >> c;
//	cout << (a + b) % c << '\n';
//	cout << ((a % c) + (b % c)) % c << '\n';
//	cout << (a*b) % c << '\n';
//	cout << ((a % c) *(b % c)) % c << '\n';
//	return 0;
//}
#pragma endregion: 나머지
#pragma region 2609
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int a,b; cin >> a>>b;
//	cout << gcd(a, b) << '\n' << lcm(a, b);
//	return 0;
//}
#pragma endregion: 최대공약수와 최소공배수
#pragma region 1934
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int a, b;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a >> b;
//		cout << lcm(a, b) << '\n';
//	}
//	return 0;
//}
#pragma endregion: 최소공배수
#pragma region 6588
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int x;
//	bool b[1000001] = { true,true, };
//	bool gold = true;
//	for (int i = 2; i < 1000001; ++i)
//	{
//		if (b[i])
//			continue;
//		for (int j = 2 * i; j < 1000001; j += i)
//		{
//			b[j] = true;
//		}
//	} // 소수부터 구함
//	while(1)
//	{
//		cin >> x;
//		if (x == 0)
//			break;
//		int a = 0, c = 0;
//		for (int j = x; j >= x / 2; --j)
//		{
//			if (!b[j] && !b[x - j])
//			{
//				a = x - j;
//				c = j;
//				gold = true;
//				break;
//			}
//			else
//				gold = false;
//		}
//		if (gold)
//			cout << x << " = " << a << " + " << c << '\n';
//		else
//			cout << "\"Goldbach's conjecture is wrong.\"" << '\n';
//	}
//	return 0;
//}
#pragma endregion: 골드바흐의 추측
#pragma region 1676
//int main()
//{
//	// 곱해서 뒤에 0이 나오는 경우는 10을 곱했을 때 뿐이다.
//	// 10 == 2 * 5 그러므로  10 을 소인수분해 
//	// 했을 때 나오는 2와 5의 개수를 세서 min(2의개수,5의개수)를 구하면 된다.
//	// 그런데 5의 개수가 항상 2의 개수보다 적기 때문에 5의 개수만 세면 된다
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int ans = 0;
//	for (int i = 5; i <= n; i *= 5)
//	{
//		ans += n / i;
//	}
//	cout << ans;
//	return 0;
//}
#pragma endregion: 팩토리얼 0의 개수
#pragma region 2004
//long long t_c(long long l)
//{
//	long long ans = 0;
//	for (long long i = 2; i <= l; i *= 2)
//	{
//		ans += l / i;
//	}
//	return ans;
//}
//long long f_c(long long l)
//{
//	long long ans = 0;
//	for (long long i = 5; i <= l; i *= 5)
//	{
//		ans += l / i;
//	}
//	return ans;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	long long a, b; cin >> a >> b;
//	long long t = t_c(a) - t_c(a - b) - t_c(b);
//	long long f = f_c(a) - f_c(a - b) - f_c(b);
//	cout << ((t > f) ? f : t);
//	
//	return 0;
//}
#pragma endregion: 조합 0의 개수

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