// BOJ 3733 :: Shares
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, s;
int main()
{
	FASTIO;
	while (cin>>n>>s)
	{
		cout << s / (n + 1) << '\n';
	}

	return 0;
}