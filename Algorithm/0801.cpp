#include <iostream>
#include <vector>
#include <wchar.h>
using namespace std;

int sum(vector<int>& v)
{
	static int A = 0;
	for (int i = 0; i < v.size();++i)
	{
		A += v[i];
	}
	return A;
}

int d(int a)
{
	int N = a;
	while (a != 0)
	{
		N = N + (a % 10);
		a = a / 10;
	}
	
	return N;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 15596
	/*unsigned int n, j;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> j;
		a.push_back(j);
	}
	cout << sum(a);*/
#pragma endregion:���� N���� ��
#pragma region 4673
	/*bool a[10001]={false,};
	int j = 1;
	for (int i = 1; i < 10001; ++i)
	{
		int n = d(i);
		if (n < 10001)
			a[n] = true;
	}
	while (j<10001)
	{
		if (!a[j])
			cout << j << '\n';
		++j;
	}*/
	
#pragma endregion:���� �ѹ�
#pragma region 1065
	/*int i = 1, j = 1, N;
	cin >> N;
	for (; i < N + 1; ++i)
	{
		if (i == 1000)
			break;
		if (100 > i) 
			j = i;
		else
		{
			int num[3];
			num[0] = i % 10;
			num[1] = (i / 10) % 10;
			num[2] = ((i / 10) / 10) % 10;
			if (num[2] - num[1] == num[1] - num[0])
				++j;
		}
	}
	cout << j;*/
#pragma endregion:�Ѽ�
#pragma region 11654
	/*char a;
	cin >> a;
	cout << (int)a;*/
#pragma endregion:�ƽ�Ű �ڵ�
#pragma region 11720
	int i, n = 0;
	char a[101]; // ������ ������ ������ ���� N(1 <= N <= 100)�ε�, 
				 // char �迭�� ���ڿ��� �Է¹ް� �Ǹ� '\0' �ι��ڰ� �������� ���ԵǹǷ�
				 // �迭�� ������ 100�� �ƴ� 101�� �������־�� �Ѵ�.
	cin >> i;
	cin >> a;
	for (int j = 0; j < i; ++j)
	{
		if (a[j] == '\0')
			break;
		n += a[j]-'0';
	}
	cout << n;
#pragma endregion::������ ��
	return 0;
}

#pragma region �����
#pragma endregion
