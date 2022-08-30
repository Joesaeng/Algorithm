// BOJ 10972 :: 다음 순열
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, t;
vector<int> v;
bool nextP = false;
void f(int a)
{
	for (int i = n - 1; i > a; --i)
	{
		if (v[a] < v[i]) // 배열의 뒤에서부터(내림차순이였던) func에서 구한 수보다 처음으로 큰 수를 찾는다.
		{
			swap(v[a], v[i]); // 찾았으면 교환
			return;
		}
	}
}
void ff(int a)
{
	for (int i = n - 1; i >= 0; --i) // 교환한 자리에서부터 오름차순으로 정렬한다.
	{
		for (int j = a; j < v.size() - 1;++j)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}
void func()
{
	for (int i = n - 1; i >= 1; --i)
	{
		if (v[i] < v[i - 1]) continue; // 배열의 뒤에서부터 내림차순이 아닌 수를 찾는다.
		f(i - 1); // 찾았다면 그 자리로 함수를 호출
		ff(i);
		nextP = true; // 여기까지 들어왔다면 다음 순열은 존재한다
		return;
	}
}

int main()
{
	FASTIO;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	func();
	if(!nextP)
		cout << "-1";
	else
	{
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
	}
	// 사실 이해가 안된듯 함

	return 0;
}