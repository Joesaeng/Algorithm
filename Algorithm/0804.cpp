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
	
#pragma endregion: ���̾�
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
#pragma endregion: ũ�ξ�Ƽ�� ���ĺ�
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
	//	if (S[i] == "") // ���ڿ��� ������ �ݺ��� Ż��
	//		break;
	//	for (int c = 0; c < S[i].size(); ++c) // ���ڿ��� ���̸�ŭ �ݺ����� ������ �� ���� üũ
	//	{
	//		for (int a = 0; a < 26; ++a) // ���ĺ� ������� ���ڸ� Ȯ��
	//		{
	//			if (S[i][c] == a + 97) 
	//			{
	//				if (B[a] == true) // �̹� ���Դ� ���ĺ� �� ��
	//				{
	//					for (int x = c-1; x >= 0; --x) // �ش� �ڸ��� �ٷ� �պ��� �������� ������ �ش� ���ĺ��� �ִ��� Ȯ��
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
		
#pragma endregion: �׷� �ܾ� üĿ
	return 0;
}



#pragma region �����
#pragma endregion