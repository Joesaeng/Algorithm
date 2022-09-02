// BOJ 10971 :: 외판원 순회 2
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, ans = INT32_MAX;
int x;
int temp = 0;
int v[10][10];
vector<int> vec;
bool b[10];
void func(int cur,int cnt)
{
	if (cnt == n - 1)
	{
		if (v[cur][x] == 0) return; // 마지막 위치에서 시작점으로 돌아갈 수 없는 경우 계산을 하지 않는다.
		for (int a : vec)
			temp += a;
		temp += v[cur][x]; // 마지막 위치에서 시작점으로 돌아가는 값을 더해준다
		ans = min(ans, temp);
		temp = 0;
		return;
	}
	b[cur] = true;
	for (int i = 0; i < n; ++i)
	{
		if (b[i] || v[cur][i] == 0) continue;
		vec.push_back(v[cur][i]);
		func(i,cnt+1);
		vec.pop_back();
	}
	b[cur] = false;
}

int main()
{
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		x = i; // 시작점
		func(i,0);
	}
	cout << ans << '\n';

	return 0;
}