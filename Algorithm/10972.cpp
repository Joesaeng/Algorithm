// BOJ 10972 :: ���� ����
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
		if (v[a] < v[i]) // �迭�� �ڿ�������(���������̿���) func���� ���� ������ ó������ ū ���� ã�´�.
		{
			swap(v[a], v[i]); // ã������ ��ȯ
			return;
		}
	}
}
void ff(int a)
{
	for (int i = n - 1; i >= 0; --i) // ��ȯ�� �ڸ��������� ������������ �����Ѵ�.
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
		if (v[i] < v[i - 1]) continue; // �迭�� �ڿ������� ���������� �ƴ� ���� ã�´�.
		f(i - 1); // ã�Ҵٸ� �� �ڸ��� �Լ��� ȣ��
		ff(i);
		nextP = true; // ������� ���Դٸ� ���� ������ �����Ѵ�
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
	// ��� ���ذ� �ȵȵ� ��

	return 0;
}