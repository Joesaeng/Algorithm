// BOJ 1920 :: ¼ö Ã£±â
#include <bits/stdc++.h>
using namespace std;
#define MAX
int n, m,t,x;
vector<int> v;
set<int> s;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		s.insert(x);
	}
		
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		if (s.find(t) != s.end())
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}


	return 0;
}