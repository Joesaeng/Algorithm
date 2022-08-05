#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <wchar.h>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 5622
	/*char c[16]={};
	int t = 0;
	cin >> c;
	if (c[0] == '\0' && c[1] == '\0') 
	{
		cout << "Error";
		return 0;
	}
	for (int i = 0; i < 16; ++i)
	{
		if (c[i] == '\0')
			break;
		if (c[i] <'A')
			t += 2;
		if (c[i] >= 'A' && c[i] <= 'C')
			t += 3;
		if (c[i] >= 'D' && c[i] <= 'F')
			t += 4;
		if (c[i] >= 'G' && c[i] <= 'I')
			t += 5;
		if (c[i] >= 'J' && c[i] <= 'L')
			t += 6;
		if (c[i] >= 'M' && c[i] <= 'O')
			t += 7;
		if (c[i] >= 'P' && c[i] <= 'S')
			t += 8;
		if (c[i] >= 'T' && c[i] <= 'V')
			t += 9;
		if (c[i] >= 'W' && c[i] <= 'Z')
			t += 10;
		if (c[i] > 'Z')
			t += 11;
	}
	cout << t;*/
	
#pragma endregion: 다이얼
#pragma region 2941
	/*string s;
	int count=0,a=0;
	cin >> s;
	count = s.length();
	if (count > 100)
		return 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != '-' && s[i] != '=' && s[i] < 'a' && s[i]>'z')
			return 0;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		if (1 <= i && s[i] == '=')
		{
			if (s[i - 1] == 'c' || s[i - 1] == 's')
			{
				count--;
			}
			else if (s[i - 1] == 'z')
			{
				if (2 <= i && s[i - 2] == 'd')
					count-=2;
				else
					count--;
			}
		}
		else if (1 <= i && s[i] == '-')
		{
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
				count--;
		}
		else if (1 <= i && s[i] == 'j')
		{
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				count--;
		}
		
	}
	cout << count;*/
#pragma endregion: 크로아티아 알파벳
#pragma region 1316
	//int N = 0,count = 0;
	//string S[100];
	//bool B[26] = { false, }, y = false;
	//
	//
	//cin >> N;
	//count = N;
	//for (int i = 0; i < N; ++i)
	//{
	//	cin >> S[i];
	//}
	//for (int i = 0; i < 100; ++i)
	//{
	//	if (S[i] == "") // 문자열이 없을때 반복문 탈출
	//		break;
	//	for (int c = 0; c < S[i].size(); ++c) // 문자열의 길이만큼 반복문을 돌려서 각 문자 체크
	//	{
	//		for (int a = 0; a < 26; ++a) // 알파벳 순서대로 문자를 확인
	//		{
	//			if (S[i][c] == a + 97) 
	//			{
	//				if (B[a] == true) // 이미 나왔던 알파벳 일 때
	//				{
	//					for (int x = c-1; x >= 0; --x) // 해당 자리의 바로 앞부터 역순으로 돌려서 해당 알파벳이 있는지 확인
	//					{
	//						if ((x>=1 && S[i][x] == S[i][x-1]) || x < 1)
	//							continue;
	//						if (S[i][x-1] == S[i][c] && y == false)
	//						{
	//							count--;
	//							y = true;
	//						}
	//					}
	//				}
	//				else
	//					B[a] = true;
	//			}
	//		}
	//	}
	//	for (int i = 0; i < 26; ++i)
	//		B[i] = false;
	//	y = false;
	//}
	//cout << count;
		
#pragma endregion: 그룹 단어 체커
	return 0;
}



#pragma region 복사용
#pragma endregion