#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <wchar.h>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#pragma region 10809
	//char s[101]; // ���ڸ� �Է¹��� ����
	//int a[26]; // ���ĺ� ����
	//for (int i = 0; i < 26; ++i)
	//	a[i] = -1; // a �迭�� ��� ���� -1�� �ʱ�ȭ
	//cin >> s;
	//for (int i = 0; i < 26; ++i)
	//{
	//	for (int j = 0; j < 100 ; ++j)
	//	{
	//		if (s[j] == '\0') // ���ڿ��� ���� �ٴٸ��� �ݺ��� Ż��
	//			break;
	//		if (i + 97 == (int)s[j] && a[i] == -1)
	//			a[i] = j;
	//	}
	//}
	//for (auto i : a)
	//	cout << i << " ";
#pragma endregion:���ĺ� ã��
#pragma region 2675
	/*int T = 0, r=0;
	vector<int> R;
	string S[1000] = {};
	string P[1000] = {};
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> r >> S[i];
		R.push_back(r);
	}
	for (int i = 0; i < T; ++i)
	{
		for (int j = 0; j < S[i].size(); ++j)
		{
			for (int k = 0; k < R[i]; ++k)
			{
				P[i] += S[i].at(j);
			}
		}
	}
	for (int i = 0; i < T; ++i)
		cout << P[i] << '\n';*/
#pragma endregion: ���ڿ� �ݺ�
#pragma region 1157
	/*int a[26] = {}, most = 0;
	char s[1000001], ans = 0;
	cin >> s;
	for (int i = 0; i < 1000001; ++i)
	{
		if (s[i] == '\0')
			break;
		for (int j = 0; j < 26; ++j)
		{
			if ((int)s[i] == j + 65 || (int)s[i] == j + 97)
				a[j]++;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (i == 0) most = a[i];
		else
		{
			if (a[i] > most)
			{
				most = a[i];
				ans = i;
			}
			else if (a[i] == most)
			{
				ans = '?';
			}
		}
	}
	if (ans == '?')
		cout << ans;
	else
		cout << char(ans + 65);*/
#pragma endregion: �ܾ� ����
#pragma region 1152
	/*string str;
	int ans = 0;
	getline(cin, str);
	if (str[0] != ' ') ans++;
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
			ans++;
	}
	cout << ans;*/
#pragma endregion:�ܾ��� ����
#pragma region 2908
	/*char A[4], B[4];
	int a, b;
	char tmp = 0;
	cin >> A >> B;
	tmp = A[0];
	A[0] = A[2];
	A[2] = tmp;
	tmp = B[0];
	B[0] = B[2];
	B[2] = tmp;
	a = stoi(A);
	b = stoi(B);
	a > b ? cout << a : cout << b;*/
#pragma endregion:���

	return 0;
}



#pragma region �����
#pragma endregion