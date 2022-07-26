#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 10818
	/*vector<int> vec;
	int n, a, max, min;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (i == 0)
		{
			max = a;
			min = a;
			vec.push_back(a);
		}
		else
		{
			vec.push_back(a);
			if (a < min)
				min = a;
			else if (a > max)
				max = a;
		}
	}
	if(min != 0)
		cout << min << " " << max;*/
#pragma endregion:최소, 최대
#pragma region 2562
	/*int arr[9];
	int a, max;
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
		if (i == 0)
		{
			a = i + 1;
			max = arr[i];
		}
		else
		{
			if (arr[i] > max)
			{
				max = arr[i];
				a = i + 1;
			}
		}
	}
	cout << max << '\n' << a;*/
#pragma endregion:최댓값
#pragma region 2577
	/*int A, B, C,x;
	int arr[10] ={};
	cin >> A >> B >> C;
	x = A * B * C;
	while (x != 0)
	{
		arr[x % 10]++;
		x /= 10;
	}
	for (int a : arr) { cout << a << '\n'; }*/ // foreach문
#pragma endregion:숫자의 개수
#pragma region 3052
	/*int B[42] = {};
	int b; int c = 0;
	for (int i=0;i<10;++i)
	{
		cin >> b;
		B[b % 42]++;
	}
	for (int i = 0; i < 42; ++i)
	{
		B[i] != 0 ? ++c : c;
	}
	cout << c;*/

		

#pragma endregion:나머지
#pragma region 1546
	//float n, a, b, c=0.f; // n : 시험 본 과목의 개수, a : 시험 점수, b : 최고점, c : 변환점수합
	//vector<float> vec;
	//cin >> n;
	//for (int i = 0; i < n; ++i)
	//{
	//	cin >> a;
	//	vec.push_back(a);
	//	i == 0 ? b = a : a > b ? b = a : b;
	//}
	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	vec[i] = vec[i] / b * 100.f;
	//	c += vec[i];
	//}
	//cout.precision(10);
	//cout << c / vec.size();

#pragma endregion:평균
#pragma region 8958
	/*int score = 0, n, a = 0;
	string s;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			s[i] == 'O' ? ++a : a = 0;
			score += a;
		}
		vec.push_back(score);
		score = 0;
		a = 0;
	}
	for (int i = 0;i < vec.size(); ++i)
		cout << vec[i] << '\n';*/
#pragma endregion:OX퀴즈
#pragma region 4344
	int c, n, a;
	float avg = 0.f, ratio = 0.f, x = 0.f, sum = 0.f;
	vector<int> vec;
	vector<float> fVec;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			vec.push_back(a);
			sum += vec[i];
		}
		avg = sum / n; // 평균
		
		for (int i = 0; i < n; ++i)
		{
			vec[i] > avg ? ++x : x; // 평균을 넘는 학생 수 x
		}
		ratio = x / n * 100;
		fVec.push_back(ratio);
		vec.clear();
		sum = 0;
		avg = 0.f;
		x = 0.f;
	}
	cout.precision(3);
	cout << fixed;
	for (int i = 0; i < fVec.size(); ++i)
		cout << fVec[i] << "%" << '\n';

#pragma endregion:평균은 넘겠지
	return 0;
}

#pragma region 복사용
#pragma endregion