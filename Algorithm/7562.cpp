// BOJ 7562 :: ����Ʈ�� �̵�
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, n, a, b;

struct Pos
{
	int y = 0;
	int x = 0;
	int cnt = 0;
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}
	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}
	bool operator<(const Pos& other) const
	{
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}
	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}
	bool Cango(int N)
	{
		return y >= 0 && x >= 0 && y < N && x < N;
	}
};
void BFS(Pos start, Pos dest,int n)
{
	int cnt = 0;
	vector<vector<bool>> disc(n + 1, vector<bool>(n + 1, false));
	Pos move[8] =
	{
		Pos{-2,-1},
		Pos{-1,-2},
		Pos{ 1,-2},
		Pos{ 2,-1},
		Pos{ 2, 1},
		Pos{ 1, 2},
		Pos{-1, 2},
		Pos{-2, 1},
	};
	queue<Pos> q;
	Pos pos = start;
	q.push(pos);
	disc[pos.y][pos.x] = true;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
		{
			cout << pos.cnt << '\n';
			return;
		}
		for (int next = 0; next < 8; ++next)
		{
			Pos nextPos = pos + move[next];
			nextPos.cnt = pos.cnt + 1;
			if (!nextPos.Cango(n)) continue;
			if (disc[nextPos.y][nextPos.x]) continue;
			q.push(nextPos);
			disc[nextPos.y][nextPos.x] = true;
		}
	}
}

int main()
{
	FASTIO;
	cin >> t;
	while (t--)
	{
		cin >> n;		// ü������ �� ���� ����
		cin >> a >> b;	// ��������
		Pos st{ a,b };
		cin >> a >> b;  // ��������
		Pos dt{ a,b };
		BFS(st, dt, n);
	}

	return 0;
}