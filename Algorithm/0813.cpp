#include <bits/stdc++.h>
using namespace std;

#pragma region 10815
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> nVec;
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a; nVec.push_back(a);
//	}
//	sort(nVec.begin(), nVec.end());
//	int m; cin >> m;
//	vector<int> mVec;
//	for (int i = 0; i < m; ++i)
//	{
//		int a; cin >> a; mVec.push_back(a);
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		if (binary_search(nVec.begin(), nVec.end(), mVec[i]))
//			cout << "1" << " ";
//		else
//			cout << "0" << " ";
//	}
//
//	return 0;
//}
#pragma endregion: 숫자 카드
#pragma region 14425
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,m; cin >> n >> m;
//	int count = 0;
//	vector<string> s;
//	for (int i = 0; i < n; ++i)
//	{
//		string a; cin >> a; s.push_back(a);
//	}
//	sort(s.begin(), s.end());
//	for (int i = 0; i < m; ++i)
//	{
//		string a; cin >> a;
//		if(binary_search(s.begin(),s.end(),a))
//			count++;
//	}
//	cout << count;
//	return 0;
//}
#pragma endregion: 문자열 집합
#pragma region 1620
//bool isNum(const string &s)
//{
//	for (char const& c : s)
//		if (isdigit(c) == 0) return false;
//	return true;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,m; cin >> n >> m;
//	vector<string> vec;
//	map<string, int> map;
//	for (int i = 1; i < n+1; ++i)
//	{
//		string s; cin >> s;
//		vec.push_back(s);
//		map.insert(make_pair(s, i));
//	}
//	for(int i = 0; i< m; ++i)
//	{
//		string s; cin >> s;
//		if (isNum(s)) // 입력으로 숫자가들어왔는지 확인
//			cout << vec[stoi(s) - 1] << '\n';
//		else
//		{
//			cout << map.at(s) << '\n';
//		}
//	} 
//	return 0;
//}
#pragma endregion: 나는야 포켓몬 마스터 이다솜
#pragma region 10816
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	map<int, int> map;
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a;
//		if (map.count(a))
//			map.at(a)++;
//		else
//			map.insert(make_pair(a, 1));
//	}
//	int m; cin >> m;
//	vector<int> mm;
//	for (int i = 0; i < m; ++i)
//	{
//		int a; cin >> a;
//		if (map.count(a))
//			mm.push_back(map.at(a));
//		else
//			mm.push_back(0);
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		cout << mm[i] << " ";
//	}
//
//	return 0;
//}
#pragma endregion: 숫자 카드 2
#pragma region 1764
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,m; cin >> n >> m;
//	string s;
//	vector<string> vec,vec_;
//	vec.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		s; cin >> vec[i];
//	}
//	sort(vec.begin(), vec.end());
//	for (int i = 0; i < m; ++i)
//	{
//		s; cin >> s;
//		if (binary_search(vec.begin(), vec.end(), s))
//			vec_.push_back(s);
//	}
//	sort(vec_.begin(), vec_.end());
//	cout << vec_.size() << '\n';
//	for (string a : vec_)
//		cout << a << '\n';
//	return 0;
//}
#pragma endregion: 듣보잡
#pragma region 1269
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,m; cin >> n >> m;
//	vector<int> a, b;
//	int sum = 0;
//	a.resize(n); b.resize(m);
//	for (int i = 0; i < n; ++i)
//		cin >> a[i];
//	for (int i = 0; i < m; ++i)
//		cin >> b[i];
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	for (int i = 0; i < n; ++i)
//	{
//		if (!binary_search(b.begin(), b.end(), a[i]))
//			sum++;
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		if (!binary_search(a.begin(), a.end(), b[i]))
//			sum++;
//	}
//	cout << sum;
//	return 0;
//}
#pragma endregion: 대칭 차집합
#pragma region 11478
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	string x;
//	int count = 0;
//	vector<string> vec;
//	vec.push_back(s);
//	for (int i = 1; i < s.size(); ++i)
//	{
//		for (int j = 0; j < s.size(); ++j)
//		{
//			x = s.substr(j, i);
//			if (x.size() < i)
//				break;
//			vec.push_back(x);
//		}
//	}
//	sort(vec.begin(), vec.end());
//	vec.erase(unique(vec.begin(), vec.end()), vec.end());
//	cout << vec.size();
//	return 0;
//}
#pragma endregion: 서로 다른 부분 문자열의 개수
#pragma region 10828
//class Stk
//{
//private:
//	int arr[10000];
//	int last;
//
//public:
//	void push(int i)
//	{
//		arr[++last] = i;
//	}
//	int pop()
//	{
//		if (last > -1)
//			return arr[last--];
//		else
//			return last;
//	}
//	int size()
//	{
//		return last + 1;
//	}
//	int empty()
//	{
//		if (last == -1)
//			return 1;
//		else return 0;
//	}
//	int top()
//	{
//		if (last > -1)
//			return arr[last];
//		else
//			return last;
//	}
//
//	Stk()
//		:arr{},last(-1)
//	{}
//};
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	string s;
//	Stk stk;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> s;
//		if (s == "push")
//		{
//			cin >> a; stk.push(a);
//		}
//		if (s == "pop")
//			cout << stk.pop() << '\n';
//		if (s == "size")
//			cout << stk.size() << '\n';
//		if (s == "empty")
//			cout << stk.empty() << '\n';
//		if (s == "top")
//			cout << stk.top() << '\n';
//	}
//	return 0;
//}
#pragma endregion: 스택
#pragma region 9093
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n; cin.ignore();
//	string s;
//	vector<vector<string>> vecS;
//	vecS.resize(n);
//	
//	for (int i = 0; i < n; ++i)
//	{
//		getline(cin, s);
//		istringstream ss(s);
//		string sss;
//		while (getline(ss, sss, ' '))
//		{
//			for (int i = 0; i < sss.size() / 2; ++i)
//			{
//				char tmp = sss[i];
//				sss[i] = sss[sss.size() - 1 - i];
//				sss[sss.size() - 1 - i] = tmp;
//			}
//			vecS[i].push_back(sss);
//		}
//	}
//	for (int i = 0; i < vecS.size(); ++i)
//	{
//		for (int j = 0; j < vecS[i].size(); ++j)
//		{
//			cout << vecS[i][j] << " ";
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}
#pragma endregion: 단어 뒤집기
#pragma region 9012
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	string s;
//	for (int i = 0; i < n; ++i)
//	{
//		int j = 0;
//		cin >> s;
//		stack<char> stk;
//		string ans = "YES";
//		for (int k = 0; k < s.size(); ++k)
//		{
//			if (s[k] == '(')
//				stk.push(s[k]);
//			else if (!stk.empty() && s[k] == ')' && stk.top() == '(')
//				stk.pop();
//			else {
//				ans = "NO";
//				break;
//			}
//		}
//		if (!stk.empty()) ans = "NO";
//		cout << ans << '\n';
//		
//	}
//	return 0;
//}
#pragma endregion: 괄호

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