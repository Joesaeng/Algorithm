// BOJ 2164 :: Ä«µå 2
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n;
void func()
{
	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	func();
	return 0;
}