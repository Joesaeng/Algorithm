#include <bits/stdc++.h>
using namespace std;

#pragma region 1874
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	stack<int> s;
//	vector<char> v;
//	bool b = true;
//	int n; cin >> n;
//	int m = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		if (a > m)
//		{
//			while (a > m)
//			{
//				s.push(++m);
//				v.push_back('+');
//			}
//			if (s.top() == a)
//			{
//				s.pop();
//				v.push_back('-');
//			}
//		}
//		else if (s.top() == a)
//		{
//			s.pop();
//			v.push_back('-');
//		}
//		else if (a < m)
//		{
//			b = false;
//			continue;
//		}
//	}
//	if (b)
//		for (auto a : v)
//			cout << a << '\n';
//	else
//		cout << "NO";
//	return 0;
//}
#pragma endregion: 스택 수열
#pragma region 1406
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	list<char> l(s.begin(),s.end());
//	list<char>::iterator iter = l.end();
//	int n; cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		char c; cin >> c;
//		if (c == 'L')
//		{
//			if (iter == l.begin())
//				continue;
//			--iter;
//		}
//		else if (c == 'D')
//		{
//			if (iter == l.end())
//				continue;
//			++iter;
//		}
//		else if (c == 'B')
//		{
//			if (iter == l.begin())
//				continue;
//			iter = l.erase(--iter);
//		}
//		else if (c == 'P')
//		{
//			char t; cin >> t;
//			l.insert(iter, t);
//		}
//		else
//			break;
//	}
//	iter = l.begin();
//	for (; iter != l.end(); ++iter)
//		cout << *iter;
//
//	
//	return 0;
//}
#pragma endregion: 에디터
#pragma region 10845
//class qu
//{
//private:
//	int arr[10000] = {0,};
//	int front=0;
//	int back=0;
//	int count = 0;
//	int size = 0;
//	int num = 1;
//public:
//	void push(int i)
//	{
//		if (0 == size)
//		{
//			arr[++count] = i;
//			front = i;
//			back = i;
//			++size;
//		}
//		else
//		{
//			arr[++count] = i;
//			back = i;
//			++size;
//		}
//	}
//	void pop()
//	{
//		if (1 > size)
//			cout << "-1" << '\n';
//		else
//		{
//			cout << front << '\n';
//			front = arr[++num];
//			--size;
//		}
//	}
//	void fsize()
//	{
//		cout << size << '\n';
//	}
//	void empty()
//	{
//		if (0 == size)
//			cout << "1" << '\n';
//		else
//			cout << "0" << '\n';
//	}
//	void ffront()
//	{
//		if (0 < size)
//			cout << front << '\n';
//		else
//			cout << "-1" << '\n';
//	}
//	void fback()
//	{
//		if (0 < size)
//			cout << back << '\n';
//		else
//			cout << "-1" << '\n';
//	}
//};
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	qu q;
//	for (int i = 0; i < n; ++i)
//	{
//		string s; cin >> s;
//		if (s == "push")
//		{
//			int x; cin >> x;
//			q.push(x);
//		}
//		if (s == "pop") 
//			q.pop();
//		if (s == "size")
//			q.fsize();
//		if (s == "empty")
//			q.empty();
//		if (s == "front")
//			q.ffront();
//		if (s == "back")
//			q.fback();
//	}
//	return 0;
//}
#pragma endregion: 큐
#pragma region 1158
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,k; cin >> n >> k;
//	list<int> l;
//	for (int i = 0; i < n; ++i)
//		l.push_back(i + 1);
//	auto iter = l.begin();
//	cout << "<";
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 1; j < k; ++j)
//		{
//			auto tmp = iter;
//			++tmp;
//			if (tmp == l.end())
//				iter = l.begin();
//			else
//				++iter;
//		}
//		if (i < n - 1)
//			cout << *iter << ", ";
//		else
//			cout << *iter;
//		auto tmp = iter;
//		++tmp;
//		if (tmp == l.end())
//		{
//			l.pop_back();
//			iter = l.begin();
//		}
//		else
//			iter = l.erase(iter);
//	}
//	cout << ">";
//	return 0;
//}
#pragma endregion: 요세푸스 문제 (리스트)
#pragma region 1158
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n,k; cin >> n >> k;
//	queue<int> q;
//	for (int i = 0; i < n; ++i)
//		q.push(i + 1);
//	cout << "<";
//	for (int i = 0; i < n-1; ++i)
//	{
//		for (int j = 1; j < k; ++j)
//		{
//			q.push(q.front());
//			q.pop();
//		}
//		cout << q.front() << ", ";
//		q.pop();
//	}
//	cout << q.front() << ">";
//	return 0;
//}
#pragma endregion: 요세푸스 문제(큐)
#pragma region 10866
//class deq
//{
//private:
//	int arr[20000]={};
//	int fpos = 10000;
//	int bpos = 10000;
//	int size = 0;
//	int front = 0;
//	int back = 0;
//public:
//	void push_front(int x)
//	{
//		if (size == 0)
//		{
//			arr[fpos] = x;
//			front = x;
//			back = x;
//			size++;
//		}
//		else
//		{
//			arr[--fpos] = x;
//			front = x;
//			size++;
//		}
//	}
//	void push_back(int x)
//	{
//		if (size == 0)
//		{
//			arr[fpos] = x;
//			front = x;
//			back = x;
//			size++;
//		}
//		else
//		{
//			arr[++bpos] = x;
//			back = x;
//			size++;
//		}
//	}
//	void pop_front()
//	{
//		if (size == 0)
//			cout << "-1" << '\n';
//		else
//		{
//			cout << front << '\n';
//			--size;
//			if (size > 0)
//			{
//				front = arr[++fpos];
//				if (size == 1)
//					back = front;
//			}
//			else
//			{
//				front = 0;
//				back = 0;
//			}
//				
//				
//		}
//	}
//	void pop_back()
//	{
//		if (size == 0)
//			cout << "-1" << '\n';
//		else
//		{
//			cout << back << '\n';
//			--size;
//			if (size > 0)
//			{
//				back = arr[--bpos];
//				if (size == 1)
//					front = back;
//			}
//			else
//			{
//				front = 0;
//				back = 0;
//			}
//
//		}
//	}
//	void fSize()
//	{
//		cout << size << '\n';
//	}
//	void fEmpty()
//	{
//		if (size == 0)
//			cout << "1" << '\n';
//		else
//			cout << "0" << '\n';
//	}
//	void fFront()
//	{
//		if (size == 0)
//			cout << "-1" << '\n';
//		else
//			cout << front << '\n';
//	}
//	void fBack()
//	{
//		if (size == 0)
//			cout << "-1" << '\n';
//		else
//			cout << back << '\n';
//	}
//};
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int x;
//	deq dq;
//	string s;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//		if (s == "push_front")
//		{
//			cin >> x; dq.push_front(x);
//		}
//		if (s == "push_back")
//		{
//			cin >> x; dq.push_back(x);
//		}
//		if (s == "pop_front") dq.pop_front();
//		if (s == "pop_back") dq.pop_back();
//		if (s == "size") dq.fSize();
//		if (s == "empty")dq.fEmpty();
//		if (s == "front")dq.fFront();
//		if (s == "back")dq.fBack();
//	}
//	return 0;
//}
#pragma endregion: 덱(Deque) : 구현
#pragma region 10866
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int x;
//	deque<int> dq;
//	string s;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> s;
//		if (s == "push_front")
//		{
//			cin >> x; dq.push_front(x);
//		}
//		if (s == "push_back")
//		{
//			cin >> x; dq.push_back(x);
//		}
//		if (s == "pop_front")
//		{
//			if (!dq.empty())
//			{
//				cout << dq.front() << '\n';
//				dq.pop_front();
//			}
//			else
//				cout << "-1" << '\n';
//		}
//		if (s == "pop_back")
//		{
//			if (!dq.empty())
//			{
//				cout << dq.back() << '\n';
//				dq.pop_back();
//			}
//			else
//				cout << "-1" << '\n';
//		}
//		if (s == "size") cout << dq.size() << '\n';
//		if (s == "empty")cout << dq.empty() << '\n';
//		if (s == "front")
//		{
//			if (!dq.empty())
//				cout << dq.front() << '\n';
//			else
//				cout << "-1" << '\n';
//		}
//		if (s == "back")
//		{
//			if (!dq.empty())
//				cout << dq.back() << '\n';
//			else
//				cout << "-1" << '\n';
//		}
//	}
//
//	return 0;
//}
#pragma endregion: 덱(Deque) : (STL)
#pragma region 17413
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s;
//	getline(cin, s);
//	vector<string> vec;
//	for (int i = 0; i < s.length(); ++i)
//	{
//		if (s[i] == '<')
//		{
//			string tmp;
//			for (; i < s.length(); ++i)
//			{
//				tmp += s[i];
//				if (s[i] == '>')
//				{
//					vec.push_back(tmp);
//					break;
//				}
//			}
//		}
//		else
//		{
//			stack<char> stk;
//			for (; i < s.length(); ++i)
//			{
//				if (s[i] == ' ')
//				{
//					break;
//				}
//				if (s[i] == '<')
//				{
//					--i; // s[i] 가 <를 체크했다면 반복문을 나가서 이번 <를 확인할수 없기 때문에 여기서 --i를 해줌
//					break;
//				}
//				else
//					stk.push(s[i]);
//			}
//			string tmp;
//			while (!stk.empty())
//			{
//				tmp += stk.top();
//				stk.pop();
//			}
//			if (s[i] == ' ')
//				tmp += ' ';
//			vec.push_back(tmp);
//		}
//	}
//	for (string a : vec)
//		cout << a;
//	return 0;
//}
#pragma endregion: 단어 뒤집기 2
#pragma region 10799
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	queue<char> qu;
//	int x = 0,count = 0;
//	for (int i = 0; i < s.length(); ++i)
//	{
//		qu.push(s[i]);
//	}
//	while (!qu.empty())
//	{
//		if (qu.front() == '(')
//		{
//			qu.pop();
//			if (qu.front() == ')')
//			{
//				count += x;
//				qu.pop();
//			}
//			else
//			{
//				++x;
//				++count;
//			}
//		}
//		if (qu.front() == ')')
//		{
//			--x;
//			qu.pop();
//		}
//	}
//	cout << count;
//	return 0;
//}
#pragma endregion: 쇠막대기(큐)
#pragma region 10799
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	string s; cin >> s;
//	int count = 0;
//	stack<char> stk;
//	for (int i = 0; i < s.length(); ++i)
//	{
//		if (s[i] == '(')
//		{
//			stk.push(s[i]);
//		}
//		else
//		{
//			stk.pop();
//			if (s[i - 1] == '(')
//			{
//				count += stk.size();
//			}
//			else
//				count++;
//		}
//	}
//	cout << count;
//	return 0;
//}
#pragma endregion: 쇠막대기(스택)


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