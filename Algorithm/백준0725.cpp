#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 2741
	/*unsigned int n = 0;
	cin >> n;

	if(100000 >= n)
		for (int i = 1; i < n + 1; ++i)
		{
			cout << i << '\n';
		}*/
#pragma endregion:N���
#pragma region 2742
	/*int n = 0;
	cin >> n;
	if(100000 >= n && 0 < n)
		for (int i = n; i > 0; --i)
		{
			cout << i << '\n';
		}*/
#pragma endregion:����N
#pragma region 11021
	/*int T ,a,b;
	
	cin >> T;
	if (1 > T)
		return 0;
	vector<int> vec;
	for (int i = 0; i < T; ++i)
	{
		cin >> a >> b;
		vec.push_back(a + b);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << "Case #" << i + 1 << ": " << vec[i] << '\n';
	}*/
#pragma endregion:A+B-7
#pragma region 11022
	/*int T;
	int a,b;

	cin >> T;
	if (1 > T)
		return 0;
	vector<int> vec1, vec2;
	for (int i = 0; i < T; ++i)
	{
		cin >> a >> b;
		vec1.push_back(a);
		vec2.push_back(b);
		
	}
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << "Case #" << i + 1 << ": " << vec1[i] << " + " << vec2[i] << " = " << vec1[i] + vec2[i] << '\n';
	}*/
#pragma endregion:A+B-8
#pragma region 2438
	/*int n;
	cin >> n;
	if (1 <= n && 100 >= n)
	{
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 0; j < i; ++j)
				cout << "*";
			cout << '\n';
		}
	}*/
#pragma endregion:�����-1
#pragma region 2439
	/*int n;
	cin >> n;
	if (1 <= n && 100 >= n)
	{
		for (int i = 1; i < n + 1; ++i)
		{
			for (int k = n; k > i; --k)
				cout << " ";
			for (int j = 0; j < i; ++j)
				cout << "*";
			cout << '\n';
		}
	}*/
#pragma endregion:�����-2
#pragma region 10871
	/*int arr[10000] = {};
	int n, x;
	int j = 0;
	cin >> n >> x;
	if (1 > x || 10000 < x || 1 > n || 10000 < n)
	{
		cout << "�Է¹��� ���� �� 1���� �۰ų� 10000���� ū ���� �ֽ��ϴ�. ���α׷��� �����մϴ�";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (1 > a || 10000 < a)
		{
			cout << "�Է¹��� ������ 1���� �۰ų� 10000���� Ů�ϴ�. ���õ˴ϴ�.";
			--i;
		}
		else
			arr[i] = a;
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < x)
			++j;
	}
	if (j < 1)
		cout << "�Է¹��� ���� ���� X���� ���� ���� �����ϴ�";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] < x)
				cout << arr[i] << " ";
		}
	}*/
#pragma endregion:X���� ���� ��
#pragma region 10952
	/*int a, b;
	vector<int> vec;
	while(true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		vec.push_back(a + b);
		
	}
	for (int i = 0; i < vec.size(); ++i)
	{
			cout << vec[i] << '\n';
	}*/
#pragma endregion:A+B-5
#pragma region 10951
	/*vector<int> vec;
	int a, b;
	while (cin >> a >> b)
	{
		vec.push_back(a + b);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << '\n';
	}*/
#pragma endregion:A+B-4
#pragma region 1110
	int n, a, b, c, d, e;
	int i = 0;
	cin >> n;
	if (0 <= n && 99 >= n)
	{
		e = n;
		while (true)
		{
			++i;
			a = e / 10;
			b = e % 10;
			c = a + b;
			d = 10 * b + c % 10;
			if (n == d) break;
			e = d;
		}
		cout << i;
	}
#pragma endregion:���ϱ� ����Ŭ
	return 0;

}
#pragma region �����
#pragma endregion