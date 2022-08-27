// BOJ 4949 :: ±ÕÇüÀâÈù ¼¼»ó
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string s;
void func()
{
	stack<char> stk;
	bool b = true;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			stk.push(s[i]);
		}
		else if (s[i] == '[')
		{
			stk.push(s[i]);
		}
		else if (!stk.empty() && s[i] == ')' && stk.top() == '(')
		{
			stk.pop();
		}
		else if (!stk.empty() && s[i] == ']' && stk.top() == '[')
		{
			stk.pop();
		}
		else if (!stk.empty() && s[i] == ')' && stk.top() != '(')
		{
			b = false;
			break;
		}
		else if (!stk.empty() && s[i] == ']' && stk.top() != '[')
		{
			b = false;
			break;
		}
		else if (stk.empty() && s[i] == ']')
		{
			b = false;
			break;
		}
		else if (stk.empty() && s[i] == ')')
		{
			b = false;
			break;
		}
	}
	if (stk.empty() && b)
		cout << "yes" << '\n';
	else
		cout << "no" << '\n';
}

int main()
{
	FASTIO;
	while (1)
	{
		getline(cin, s);
		if (s == ".")
			break;
		func();
	}

	return 0;
}