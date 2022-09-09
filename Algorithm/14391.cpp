// BOJ 14391 :: 종이 조각
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
int v[4][4];
int ans = 0;
string s;
void func(int N, int M, int nm, int mm, int sum)
{
	if (nm - 1 == N) // 단 한 줄의 행만 남아있을때
	{
		int tmp = 0;
		for(int i = M; i < mm; ++i)
			tmp += v[N][i] * (int)pow((int)10, (int)(mm - i - 1)); 
		sum += tmp; // 남은 행을 더해줌
		ans = max(ans, sum); // 최대값 도출
		return;
	}
	if (mm - 1 == M) // 단 한 줄의 열만 남아있을 때
	{
		int tmp = 0;
		for (int i = N; i < nm; ++i)
			tmp += v[i][M] * (int)pow((int)10, (int)(nm - i - 1));
		sum += tmp; // 남은 열을 더해줌
		ans = max(ans, sum); // 최대값
		return;
	}

	int tp1=0, tp2=0;
	int a = 0, b = 0;
	for (int i = N; i < nm; ++i)
	{
		if (i != N && i != nm - 1) continue; // 행의 테두리
		int tmp = 0;
		for (int j = M; j < mm; ++j)
		{
			tmp += v[i][j] * (int)pow((int)10, (int)(mm-j-1));
		}
		if(i == N) func(N + 1, M, nm, mm, sum + tmp); // 첫번째 행을 잘라냈을 때
		else func(N, M, nm - 1, mm, sum + tmp);		  // 마지막 행
	}

	for (int i = M; i < mm; ++i)
	{
		if (i != M && i != mm - 1) continue; // 열의 테두리
		int tmp = 0;
		for (int j = N; j < nm; ++j)
		{
			tmp += v[j][i] * (int)pow((int)10, (int)(nm - j - 1));
		}
		if(i == M) func(N, M + 1, nm, mm, sum + tmp); // 첫번째 열을 잘라냈을 때
		else func(N, M, nm, mm - 1, sum + tmp);		  // 마지막 열
	}

	// 지금 for문 안에 있는 재귀함수를 돌리는 부분이 원래는 첫번째 행(열) 과 마지막 행(열)
	// 둘 중의 큰 값을 잘라낸 후에 지금 이 자리에서 재귀를 했는데, 인터넷에 있던
	// 반례와 테스트케이스 등등은 잘 나왔으나, 계속 틀렸다고 나왔다.
	// 따로 반례를 찾아두진 않았지만, 혼자 생각해보니 첫번째 행(열) 보다 마지막 행(열)
	// 이 크다면 마지막 행을 자르는 경우만 계산했는데, 첫번째 행 (작은 행) 을 먼저 자르면
	// 더 클수도 있지 않을까? 라는 생각이 났고. 그래서 for문 안쪽에다 재귀함수를 돌리는 부분을 넣어줬다.
	// 그랬더니 맞았다.
	// 결국 승리했다! 시팔!
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