// BOJ 10971 :: ���ǿ� ��ȸ 2
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
		if (v[cur][x] == 0) return; // ������ ��ġ���� ���������� ���ư� �� ���� ��� ����� ���� �ʴ´�.
		for (int a : vec)
			temp += a;
		temp += v[cur][x]; // ������ ��ġ���� ���������� ���ư��� ���� �����ش�
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
		x = i; // ������
		func(i,0);
	}
	cout << ans << '\n';

	return 0;
}