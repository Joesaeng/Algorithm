// BOJ 15649 :: N°ú M (1)
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int arr[9];
bool b[9];
vector<int> v;
void Prt()
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
}
void func(int a)
{
	if (a == m)
	{
		Prt();
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (b[i]) continue;
		b[i] = true;
		v.push_back(arr[i]);
		func(a + 1);
		v.pop_back();
		b[i] = false;
	}

}

int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		arr[i] = i + 1;
	func(0);
	return 0;
}