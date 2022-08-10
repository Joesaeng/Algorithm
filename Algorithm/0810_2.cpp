#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
#pragma region 2798
//int main()
//{
//
//	int n, m, ans = 0;
//	cin >> n >> m;
//	vector<int> vec;
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a;
//		vec.push_back(a);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int s[3]={};
//		s[0] = vec[i];
//		for (int j = i+1; j < n; ++j)
//		{
//			s[1] = vec[j];
//			for (int k = j+1; k < n; ++k)
//			{
//				s[2] = vec[k];
//				if (s[0] + s[1] + s[2] <= m && s[0] + s[1] + s[2] > ans)
//				{
//					ans = s[0] + s[1] + s[2];
//				}
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}
#pragma endregion: 블랙잭
#pragma region 2231
//int sum(int a)
//{
//	int sum = 0;
//	while (a > 0)
//	{
//		sum += a % 10;
//		a /= 10;
//	}
//	return sum;
//}
//int main()
//{
//	int n, i = 1;
//	cin >> n;
//	while (n != i + sum(i))
//	{
//		++i;
//		if (i > n)
//		{
//			i = 0;
//			break;
//		}
//	}
//	cout << i;
//	return 0;
//}
#pragma endregion: 분해합
#pragma region 7568
//struct kk
//{
//	int kg;
//	int height;
//public:
//	kk()
//		:kg(0), height(0)
//	{}
//	bool operator <(kk k)
//	{
//		if (kg < k.kg && height < k.height)
//			return true;
//		else return false;
//	}
//	void set(int a, int b)
//	{
//		kg = a;
//		height = b;
//	}
//};
//int main()
//{
//	int n, x, y, rank[50]={};
//	kk arr[50];
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> x >> y;
//		arr[i].set(x,y);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int k = 1;
//		for (int j = 0; j < n; ++j)
//		{
//			if (arr[i] < arr[j])
//				++k;
//		}
//		rank[i] = k;
//	}
//	for (auto a : rank)
//	{
//		if (a == 0)
//			break;
//		cout << a << " ";
//	}
//		
//	return 0;
//}
#pragma endregion: 덩치
#pragma region 1018
//int check(vector<string> board, int x, int y)
//{
//	int cntW = 0,cntB = 0;
//	if (board.size() - x >= 8 && board[x].length() - y >= 8)
//	{
//		{
//			string s[8] = 
//			{	"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//			};
//			int si=0, sj;
//			for (int i = x; i < x + 8; ++i)
//			{
//				sj = 0;
//				for (int j = y; j < y + 8; ++j)
//				{
//					if (board[i][j] != s[si][sj])
//						cntW++;
//					++sj;
//				}
//				++si;
//			}
//		}
//		{
//			string s[8] =
//			{	"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB",
//				"BWBWBWBW",
//				"WBWBWBWB"
//			};
//			int si=0, sj;
//			for (int i = x; i < x + 8; ++i)
//			{
//				sj = 0;
//				for (int j = y; j < y + 8; ++j)
//				{
//					if (board[i][j] != s[si][sj])
//						cntB++;
//					++sj;
//				}
//				++si;
//			}
//		}
//		if (cntW > cntB)
//			return cntB;
//		else return cntW;
//	}
//	return 100;
//}
//int main()
//{
//	int x, y,ans=100;
//	vector<string> board;
//	cin >> x >> y;
//	for (int i = 0; i < x; ++i)
//	{
//		string s, s1;
//		cin >> s;
//		s1 = s.substr(0, y);
//		board.push_back(s1);
//	}
//	for (int i = 0; i < x; ++i)
//	{
//		for (int j = 0; j < y; ++j)
//		{
//			if (ans > check(board, i, j))
//				ans = check(board, i, j);
//		}
//	}
//	cout << ans;
//	return 0;
//}
#pragma endregion: 체스판 다시 칠하기
#pragma region 1436
int main()
{
	int n, b = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		while (true)
		{
			++b;
			string s;
			s = to_string(b);
			if (s.find("666") != string::npos)
			{
				ans = b;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
#pragma endregion: 영화감독 숌



#pragma region 복사용
//int main()
//{
//
//	return 0;
//}
#pragma endregion