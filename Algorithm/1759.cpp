// BOJ 1759 :: 암호 만들기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
char c[15];
char ans[15];
int mo = 0;
int l, n;
void DFS(int depth,int num)
{
	if (depth == l)
	{
		if (mo == 0 || l - mo < 2) return;
		for (int i = 0; i < l; ++i)
			cout << ans[i];
		cout << '\n';
		return;
	}
	for (int i = num; i < n; ++i)
	{
		ans[depth] = c[i];
		if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
		{
			mo++;
			DFS(depth + 1, i + 1);
			mo--;
		}
		else
			DFS(depth + 1, i + 1);
	}
}

int main()
{
	FASTIO;
	cin >> l >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	sort(c, c + n);
	DFS(0, 0);
	return 0;
}