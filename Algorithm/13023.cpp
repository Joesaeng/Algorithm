// BOJ 13023 :: ABCDE
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 2000
using namespace std;
int n, m,a,b;
vector<vector<int>> v(MAX);
int cnt[MAX] = {};
bool vi[MAX] = {false,};
bool flag = false;
void func(int cur,int cnt)
{
	if (cnt == 4)
	{
		flag = true;
		return;
	}
	vi[cur] = true;
	for (int i = 0; i < v[cur].size(); ++i)
	{
		int next = v[cur][i];
		if (vi[next]) continue;
		func(next,cnt+1);
		if (flag) return;
	}
	vi[cur] = false;
}

int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		memset(vi, false, sizeof(vi));
		func(i, 0);
		if (flag) break;
	}
	if (flag) cout << "1";
	else cout << "0";

	return 0;
}