// BOJ 14391 :: ���� ����
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int v[4][4];
int ans = 0;
string s;
void func(int N, int M, int nm, int mm, int sum)
{
	if (nm - 1 == N) // �� �� ���� �ุ ����������
	{
		int tmp = 0;
		for(int i = M; i < mm; ++i)
			tmp += v[N][i] * (int)pow((int)10, (int)(mm - i - 1)); 
		sum += tmp; // ���� ���� ������
		ans = max(ans, sum); // �ִ밪 ����
		return;
	}
	if (mm - 1 == M) // �� �� ���� ���� �������� ��
	{
		int tmp = 0;
		for (int i = N; i < nm; ++i)
			tmp += v[i][M] * (int)pow((int)10, (int)(nm - i - 1));
		sum += tmp; // ���� ���� ������
		ans = max(ans, sum); // �ִ밪
		return;
	}

	int tp1=0, tp2=0;
	int a = 0, b = 0;
	for (int i = N; i < nm; ++i)
	{
		if (i != N && i != nm - 1) continue; // ���� �׵θ�
		int tmp = 0;
		for (int j = M; j < mm; ++j)
		{
			tmp += v[i][j] * (int)pow((int)10, (int)(mm-j-1));
		}
		if(i == N) func(N + 1, M, nm, mm, sum + tmp); // ù��° ���� �߶���� ��
		else func(N, M, nm - 1, mm, sum + tmp);		  // ������ ��
	}

	for (int i = M; i < mm; ++i)
	{
		if (i != M && i != mm - 1) continue; // ���� �׵θ�
		int tmp = 0;
		for (int j = N; j < nm; ++j)
		{
			tmp += v[j][i] * (int)pow((int)10, (int)(nm - j - 1));
		}
		if(i == M) func(N, M + 1, nm, mm, sum + tmp); // ù��° ���� �߶���� ��
		else func(N, M, nm, mm - 1, sum + tmp);		  // ������ ��
	}

	// ���� for�� �ȿ� �ִ� ����Լ��� ������ �κ��� ������ ù��° ��(��) �� ������ ��(��)
	// �� ���� ū ���� �߶� �Ŀ� ���� �� �ڸ����� ��͸� �ߴµ�, ���ͳݿ� �ִ�
	// �ݷʿ� �׽�Ʈ���̽� ����� �� ��������, ��� Ʋ�ȴٰ� ���Դ�.
	// ���� �ݷʸ� ã�Ƶ��� �ʾ�����, ȥ�� �����غ��� ù��° ��(��) ���� ������ ��(��)
	// �� ũ�ٸ� ������ ���� �ڸ��� ��츸 ����ߴµ�, ù��° �� (���� ��) �� ���� �ڸ���
	// �� Ŭ���� ���� ������? ��� ������ ����. �׷��� for�� ���ʿ��� ����Լ��� ������ �κ��� �־����.
	// �׷����� �¾Ҵ�.
	// �ᱹ �¸��ߴ�! ����!
}
int main()
{
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
			v[i][j] = s[j] - '0';
	}
	func(0, 0, n, m, 0);
	cout << ans;
	return 0;
}