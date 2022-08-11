#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#pragma region 2750
//void jSort(vector<int>& vec, int size)
//{
//	// 버블정렬 알고리즘 : 배열에 안에 있는 연속된 데이터를 비교하여 데이터가 크거나 작을때 데이터를 우측으로 이동시키는 알고리즘
//	int i, j, temp;
//
//	if (size <= 1)
//		return;
//
//	for (i = 0; i < size; ++i)
//	{
//		for (j = 0; j < size - i - 1; ++j)
//		{
//			if (vec[j] > vec[j + 1])
//			{
//				temp = vec[j];
//				vec[j] = vec[j + 1];
//				vec[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> vec;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		vec.push_back(a);
//	}
//	jSort(vec,vec.size());
//	for (int i = 0; i < vec.size(); ++i)
//		cout << vec[i] << '\n';
//
//	
//	return 0;
//}
#pragma endregion: 수 정렬하기
#pragma region 2751
//	int n;int* arr, *arr2;
//void Sort(int left, int right)
//{
//	int mid = (left + right) / 2;
//	int i = left;
//	int j = mid + 1;
//	int k = left;
//	while (i <= mid && j <= right)
//	{
//		if (arr[i] > arr[j])
//			arr2[k++] = arr[j++];
//		else
//			arr2[k++] = arr[i++];
//	}
//	if (i > mid)
//	{
//		while (j <= right)
//			arr2[k++] = arr[j++];
//	}
//	else
//	{
//		while (i <= mid)
//			arr2[k++] = arr[i++];
//	}
//
//	for (int a = left; a <= right; a++)
//		arr[a] = arr2[a];
//
//}
//void mergeSort(int left, int right)
//{
//	if (left < right)
//	{
//		int mid = (left + right) / 2;
//		mergeSort(left, mid);
//		mergeSort(mid + 1, right);
//		Sort(left, right);
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	arr = new int[n];
//	arr2 = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a; arr[i] = a;
//	}
//	mergeSort(0, n-1);
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << '\n';
//	}
//
//
//
//	return 0;
//}
#pragma endregion: 수 정렬하기 2
#pragma region 10989
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int arr2[10001] = {};
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a;
//		arr2[a]++;
//	}
//	for (int i = 1; i < 10001; ++i)
//	{
//		if (arr2[i] != 0)
//		{
//			for (int j = 0; j < arr2[i]; ++j)
//				cout << i << '\n';
//		}
//	}
//	return 0;
//}
#pragma endregion: 수 정렬하기 3
#pragma region 25305
//bool compare(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n, k; cin >> n >> k;
//	int N[1000] = {};
//	for (int i = 0; i < n; ++i)
//	{
//		int a; cin >> a; N[i] = a;
//	}
//	sort(N,N+n,compare);
//	cout << N[k - 1];
//	return 0;
//}
#pragma endregion: 커트라인
#pragma region 2108
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	int* arr = new int[n];
//	int cnt[8001] = {};
//	int many[2] = {};
//	int sum = 0, count = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//		sum += arr[i];
//		cnt[arr[i] + 4000]++;
//	}
//	for (int i = 0; i < 8001; ++i)
//	{
//		if (cnt[i] > count)
//		{
//			count = cnt[i];
//			many[0] = i - 4000;
//			many[1] = many[0];
//		}
//		else if (cnt[i] == count)
//		{
//			if (i - 4000 < many[0] && i - 4000 < many[1])
//			{
//				many[1] = many[0];
//				many[0] = i - 4000;
//			}
//			else if (i - 4000 > many[0] && many[0] == many[1] || i - 4000 > many[0] && i - 4000 < many[1])
//			{
//				many[1] = i - 4000;
//			}
//		}
//	}
//	sort(arr, arr + n);
//	cout << int(round(double(sum) / double(n))) << '\n'; // 산술평균
//	cout << arr[n / 2] << '\n';				// 중앙값
//	cout << many[1] << '\n';				// 최빈값 출력, 여러개 있으면 최빈값중 두번째로 작은 값
//	cout << abs(arr[n-1] - arr[0]) << '\n'; // 범위
//
//	delete [] arr;
//	return 0;
//}
#pragma endregion: 통계학
#pragma region 1427
//bool compare(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vector<int> vec;
//	while (n > 0)
//	{
//		vec.push_back(n % 10);
//		n /= 10;
//	}
//	vector<int>::iterator iter = vec.begin();
//	sort(iter, vec.end(), compare);
//	for (int i = 0; i < vec.size(); ++i)
//		cout << vec[i];
//
//	return 0;
//}
#pragma endregion: 소트인사이드
#pragma region 11650
//struct vec2
//{
//	int x, y;
//public:
//	void set(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//	bool operator >(vec2 vec)
//	{
//		if (x > vec.x)
//			return true;
//		if (x == vec.x && y > vec.y)
//			return true;
//		return false;
//	}
//	bool operator <(vec2 vec)
//	{
//		if (x < vec.x)
//			return true;
//		if (x == vec.x && y < vec.y)
//			return true;
//		return false;
//	}
//	void operator =(vec2 vec)
//	{
//		x = vec.x;
//		y = vec.y;
//	}
//};
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vec2* vec = new vec2[n];
//	for (int i = 0; i < n; ++i)
//	{
//		int a, b; cin >> a >> b;
//		vec[i].set(a, b);
//	}
//	sort(vec, vec + n);
//	for (int i = 0; i < n; ++i)
//		cout << vec[i].x << " " << vec[i].y << '\n';
//	return 0;
//}
#pragma endregion: 좌표 정렬하기
#pragma region 11651
//struct vec2
//{
//	int x, y;
//public:
//	void set(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//	bool operator >(vec2 vec)
//	{
//		if (y > vec.y)
//			return true;
//		if (y == vec.y && x > vec.x)
//			return true;
//		return false;
//	}
//	bool operator <(vec2 vec)
//	{
//		if (y < vec.y)
//			return true;
//		if (y == vec.y && x < vec.x)
//			return true;
//		return false;
//	}
//	void operator =(vec2 vec)
//	{
//		x = vec.x;
//		y = vec.y;
//	}
//};
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	vec2* vec = new vec2[n];
//	for (int i = 0; i < n; ++i)
//	{
//		int a, b; cin >> a >> b;
//		vec[i].set(a, b);
//	}
//	sort(vec, vec + n);
//	for (int i = 0; i < n; ++i)
//		cout << vec[i].x << " " << vec[i].y << '\n';
//	return 0;
//}
#pragma endregion: 좌표 정렬하기 2
#pragma region 1181
//bool compare(string a,string b)
//{
//	if (a.size() == b.size())
//		return a < b;
//	else return a.size() < b.size();
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	string* s = new string[n];
//	for (int i = 0; i < n; ++i)
//		cin >> s[i];
//	sort(s,s+n,compare);
//
//
//	cout << s[0] << '\n';
//	for (int i = 1; i < n; ++i)
//		if(s[i] != s[i-1])cout << s[i] << '\n';
//	return 0;
//}
#pragma endregion: 단어 정렬
#pragma region 10814
//struct user
//{
//	int age;
//	string name;
//};
//bool compare(user a,user b)
//{
//	return a.age < b.age;
//}
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	user* u = new user[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> u[i].age >> u[i].name;
//	}
//
//	stable_sort(u, u + n,compare);
//	for (int i = 0; i < n; ++i)
//	{
//		cout << u[i].age << " " << u[i].name << '\n';
//	}
//	return 0;
//}
#pragma endregion: 나이순 정렬
#pragma region 18870

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> vec, vec2;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		vec.push_back(a);
		vec2.push_back(a);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < vec2.size(); ++i)
	{
		cout << lower_bound(vec.begin(), vec.end(), vec2[i]) - vec.begin() << " "; // 반환된 이터레이터를 실제로 인덱스값으로 받아오기 위해 배열의 이름(vector의 경우 begin)을 빼줌
		// lower_bound == 이진 탐색으로 원소를 찾으면서 찾으려는 key값보다 같거나 큰 숫자가 처음 등장하는 인덱스값의 이터레이터를 반환함
		// upper_bound == 이진 탐색으로 원소를 찾으면서 찾으려는 key값을 초과하는 숫자가 처음 등장하는 인덱스값의 이터레이터를 반환함
		// lower_bound(start, end, key)
	}
	return 0;
}
#pragma endregion: 좌표 압축


#pragma region 복사용
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n; cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//
//	}
//	return 0;
//}
#pragma endregion