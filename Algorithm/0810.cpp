#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int i = 0, j = 0;
int fact(int a) // 10872 ���丮��
{
	if (0 == i)
	{
		if (0 == a)
			return 1;
		i = a;
	}
		
	if (1 == i) {i = 0; return a;}
	return fact(a *= --i);
}
int fibo(int a) // 10870 �Ǻ���ġ �� 5
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	return fibo(a - 1) + fibo(a - 2);
}
int whatIsRecus(int a) // 17478 ����Լ��� ������?
{
	if (a == 0) 
	{
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "\"����Լ��� ������?\"" << '\n';
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "��� �亯�Ͽ���." << '\n';
		return 0;
	}
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "\"����Լ��� ������?\"" << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
	i++;
	whatIsRecus(a - 1);
	i--;
	for (int j = 0; j < i;++j) cout << "____";
	cout << "��� �亯�Ͽ���." << '\n';
	return 0;
}
void star(int a, int b, int c) // 2447 �� ��� - 10
{
	if (a / c % 3 == 1 && b / c % 3 == 1) 
	{
		cout << " ";
	}
	else if (c / 3 == 0) 
	{
		cout << "*";
	}
	else 
	{
		star(a, b, c / 3);
	}
}
void hanoi(int n,int from,int sub, int to) // 11729 �ϳ��� ž
{
	if (n == 1)
		cout << from << " " << to << '\n';
	else
	{
		hanoi(n - 1, from, to, sub);
		cout << from << " " << to << '\n';
		hanoi(n - 1, sub, from, to);
	}
	
}
int main()
{
#pragma region 10872
	/*int n;
	cin >>n;
	n = fact(n);
	cout << n << '\n';*/
#pragma endregion: ���丮��
#pragma region 10870
	/*int n;
	cin >> n;
	n = fibo(n);
	cout << n << '\n';*/
#pragma endregion: �Ǻ���ġ �� 5
#pragma region 17478
	/*int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	whatIsRecus(n);*/
#pragma endregion: ����Լ��� ������?
#pragma region 2447
	/*int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			star(i, j, n);
		}
		cout << '\n';
	}*/
#pragma endregion �� ��� - 10
#pragma region 11729
	int n = 0;
	cin >> n;
	cout << int(pow(2, n) - 1) << '\n';
	hanoi(n,1,2,3);

#pragma endregion: �ϳ��� ž �̵� ����
	return 0;
}
#pragma region �����
#pragma endregion