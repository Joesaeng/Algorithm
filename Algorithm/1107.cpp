// BOJ 1107 :: ¸®¸ğÄÁ
#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
string sets = "100";
string target;
int brkCnt;
char brk[10];
vector<char> btn;
int cnt = 0;
void func()
{
	if (target == sets)
	{
		cout << cnt;
		return;
	}
	
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