// BOJ 15665 :: N°ú M (11)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
vector<int> arr;
set<vector<int>> st;
int in[8 + 1];
//bool s[8 + 1];
void func(int cnt)
{
	if (cnt == m + 1)
	{
		for (int i = 1; i <= m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		//st.insert(arr);
		return;
	}
	int t = 0;
	for (int i = 1; i <= n; ++i)
	{
		//if (s[i]) continue;
		if (t == in[i]) continue;
		arr[cnt] = in[i];
		t = in[i];
		//s[i] = true;
		func(cnt + 1);
		//s[i] = false;
	}
}

int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> in[i];
	sort(in, in + n + 1);
	arr.resize(n + 1);
	func(1);
	/*for (auto iter = st.begin(); iter != st.end(); ++iter)
	{
		vector<int> v = static_cast<vector<int>>(*iter);
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i])
			cout << v[i] << " ";
		}
		cout << '\n';
	}*/


	return 0;
}