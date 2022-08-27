// BOJ 11866 :: 요세푸스 문제 0
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 + 1
int n, k;
queue<int> q;
void func()
{
	int i = 1;
	cout << "<";
	while (!q.empty())
	{
		if (i == k)
		{
			cout << q.front();
			q.pop();
			if(!q.empty())
				cout << ", ";
			i = 1;
		}
		else
		{
			q.push(q.front());
			q.pop();
			++i;
		}
	}
	cout << ">";
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	func();


	return 0;
}