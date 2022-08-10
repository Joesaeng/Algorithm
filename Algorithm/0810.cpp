#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int i = 0, j = 0;
int fact(int a) // 10872 팩토리얼
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
int fibo(int a) // 10870 피보나치 수 5
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	return fibo(a - 1) + fibo(a - 2);
}
int whatIsRecus(int a) // 17478 재귀함수가 뭔가요?
{
	if (a == 0) 
	{
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "\"재귀함수가 뭔가요?\"" << '\n';
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
		for (int j = 0; j < i; ++j) cout << "____";
		cout << "라고 답변하였지." << '\n';
		return 0;
	}
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "\"재귀함수가 뭔가요?\"" << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
	for (int j = 0; j < i; ++j) cout << "____";
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
	i++;
	whatIsRecus(a - 1);
	i--;
	for (int j = 0; j < i;++j) cout << "____";
	cout << "라고 답변하였지." << '\n';
	return 0;
}
void star(int a, int b, int c) // 2447 별 찍기 - 10
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
void hanoi(int n,int from,int sub, int to) // 11729 하노이 탑
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
#pragma endregion: 팩토리얼
#pragma region 10870
	/*int n;
	cin >> n;
	n = fibo(n);
	cout << n << '\n';*/
#pragma endregion: 피보나치 수 5
#pragma region 17478
	/*int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
	whatIsRecus(n);*/
#pragma endregion: 재귀함수가 뭔가요?
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
#pragma endregion 별 찍기 - 10
#pragma region 11729
	int n = 0;
	cin >> n;
	cout << int(pow(2, n) - 1) << '\n';
	hanoi(n,1,2,3);

#pragma endregion: 하노이 탑 이동 순서
	return 0;
}
#pragma region 복사용
#pragma endregion