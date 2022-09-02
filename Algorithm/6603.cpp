// BOJ 6603  :: ·Î¶Ç
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t;
vector<int> vec(13);
int v[6];
void func(int r, int cnt, int idx)
{
	if (r == 0)
	{
		for (int a : v)
			cout << a << ' ';
		cout << '\n';
		return;
	}
	else if (cnt == t) return;
	else
	{
		v[idx] = vec[cnt];
		func(r-1, cnt + 1, idx + 1);

		func(r, cnt + 1, idx);
	}
}

int main()
{
	FASTIO;
	while (1)
	{
		cin >> t;
		if (t == 0) break;
		for (int i = 0; i < t; ++i)
		{
			cin >> vec[i];
		}
		func(6, 0, 0);
		cout << '\n';
	}

	return 0;
}