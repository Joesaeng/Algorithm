// BOJ 10773 :: Á¦·Î
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
stack<int> s;
int n;
int a;
int sum;
int main()
{
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (a == 0 && !s.empty())
		{
			s.pop();
		}
		else
		{
			s.push(a);
		}
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return 0;
}