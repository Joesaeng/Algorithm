#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#pragma region 2750
//void jSort(vector<int>& vec, int size)
//{
//	// �������� �˰��� : �迭�� �ȿ� �ִ� ���ӵ� �����͸� ���Ͽ� �����Ͱ� ũ�ų� ������ �����͸� �������� �̵���Ű�� �˰���
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
#pragma endregion: �� �����ϱ�
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
#pragma endregion: �� �����ϱ� 2
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
#pragma endregion: �� �����ϱ� 3
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
#pragma endregion: ĿƮ����
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
//	cout << int(round(double(sum) / double(n))) << '\n'; // ������
//	cout << arr[n / 2] << '\n';				// �߾Ӱ�
//	cout << many[1] << '\n';				// �ֺ� ���, ������ ������ �ֺ��� �ι�°�� ���� ��
//	cout << abs(arr[n-1] - arr[0]) << '\n'; // ����
//
//	delete [] arr;
//	return 0;
//}
#pragma endregion: �����
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
#pragma endregion: ��Ʈ�λ��̵�
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
#pragma endregion: ��ǥ �����ϱ�
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
#pragma endregion: ��ǥ �����ϱ� 2
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
#pragma endregion: �ܾ� ����
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
#pragma endregion: ���̼� ����
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
		cout << lower_bound(vec.begin(), vec.end(), vec2[i]) - vec.begin() << " "; // ��ȯ�� ���ͷ����͸� ������ �ε��������� �޾ƿ��� ���� �迭�� �̸�(vector�� ��� begin)�� ����
		// lower_bound == ���� Ž������ ���Ҹ� ã���鼭 ã������ key������ ���ų� ū ���ڰ� ó�� �����ϴ� �ε������� ���ͷ����͸� ��ȯ��
		// upper_bound == ���� Ž������ ���Ҹ� ã���鼭 ã������ key���� �ʰ��ϴ� ���ڰ� ó�� �����ϴ� �ε������� ���ͷ����͸� ��ȯ��
		// lower_bound(start, end, key)
	}
	return 0;
}
#pragma endregion: ��ǥ ����


#pragma region �����
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