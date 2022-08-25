// BOJ 1107 :: ¸®¸ðÄÁ
#include <bits/stdc++.h>
using namespace std;
int def = 100;
int target;
string ts;
int brkCnt;
char brk[10];
vector<char> btn;
char val[6];
string tmp;
int cnt = 0;
int mod = 0;
int t = 499900;
int t1 = 499900;
int t2 = 499900;
void DFS(int CNT)
{
	if (CNT == ts.length())
	{
		for (int i = 0; i < ts.length(); ++i)
		{
			tmp += val[i];
		}
		if(abs(target - stoi(tmp)) >= 0)
			t = min(t, abs(target - stoi(tmp)));
		tmp = "";
		return;
	}

	for (int i = 0; i < btn.size(); ++i)
	{
		val[CNT] = btn[i];
		DFS(CNT + 1);
	}
}
void DFS1(int CNT)
{
	if (CNT == ts.length() - 1)
	{
		for (int i = 0; i < ts.length() - 1; ++i)
		{
			tmp += val[i];
		}
		if (abs(target - stoi(tmp)) >= 0)
			t1 = min(t1, abs(target - stoi(tmp)));
		tmp = "";
		return;
	}

	for (int i = 0; i < btn.size(); ++i)
	{
		val[CNT] = btn[i];
		DFS1(CNT + 1);
	}
}
void DFS2(int CNT)
{
	if (CNT == ts.length() + 1)
	{
		for (int i = 0; i < ts.length() + 1; ++i)
		{
			tmp += val[i];
		}
		if (abs(target - stoi(tmp)) >= 0 && tmp[0] != '0')
			t2 = min(t2, abs(target - stoi(tmp)));
		tmp = "";
		return;
	}
	for (int i = 0; i < btn.size(); ++i)
	{
		val[CNT] = btn[i];
		DFS2(CNT + 1);
	}
}
void func()
{
	ts = to_string(target);
	mod = abs(def - target);
	if (target == def)
	{
		cout << cnt;
		return;
	}
	if (brkCnt == 0)
	{
		cnt = min(mod, (int)ts.length());
		cout << cnt;
		return;
	}
	DFS(0);
	if(ts.length() > 1)
		DFS1(0);
	DFS2(0);
	cnt = (mod < t + ts.length()) && (mod < t1 + ts.length() - 1) && (mod < t2 + ts.length() + 1) ? mod
		: (t + ts.length() < mod) && (t + ts.length() < t1 + ts.length() - 1) && (t + ts.length() < t2 + ts.length() + 1) ? t + ts.length()
		: (t1 + ts.length() - 1 < mod) && (t1 + ts.length() - 1 < t2 + ts.length() + 1) && (t1 + ts.length() - 1 < t + ts.length()) ? t1 + ts.length() - 1
		: t2 + ts.length() + 1;

	cout << cnt;
}

int main()
{
	cin >> target >> brkCnt;
	for (int i = 0; i < brkCnt; ++i)
	{
		cin >> brk[i];
	}
	for (int i = 0; i < 10; ++i)
	{
		bool b = true;
		for (int j = 0; j < brkCnt; ++j)
		{
			if (i + '0' == brk[j])
			{
				b = false;
				break;
			}
		}
		if (b)
			btn.push_back(i + '0');
	}
	func();


	return 0;
}