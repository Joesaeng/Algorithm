// BOJ 11779 :: �ּҺ�� ���ϱ� 2
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n,m;
int a, b, c;
int ans, cnt;
vector<vector<pair<int, int>>> road;
map<int, int> parent; // parent[i] = a :: i��ġ�� ã�� ��ġ�� a
vector<int> path;
// ���ͽ�Ʈ�� �˰���
void func(int start, int dest)
{
	int pos = start;
	vector<int> dist = vector<int>(n + 1, INF);
	priority_queue<pair<int, int>> q;
	parent[pos] = pos;
	dist[pos] = 0;
	q.push(pair{ 0,pos });

	while (!q.empty())
	{
		int cost = -q.top().first;
		pos = q.top().second;
		q.pop();

		if (pos == dest)
		{
			ans = cost;
			break;
		};

		for (int i = 0; i < road[pos].size(); ++i)
		{
			int next = road[pos][i].second;
			int nCost = road[pos][i].first;
			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				parent[next] = pos;
				q.push(pair{ -dist[next], next });
			}
		}
	}
	pos = dest; // ���������� �������� Ž��
	cnt = 1;
	while (1)
	{
		path.push_back(pos); // ���� ��ġ�� ��ο� �ִ´�
		if (pos == parent[pos]) // �θ� �ڱ� �ڽ��̸� ������
			break;
		pos = parent[pos];
		cnt++;
	}
	reverse(path.begin(), path.end()); // �����̴� ��������
}
int main()
{
    FASTIO;
	cin >> n >> m; // n���� ����, m���� ����
	road = vector<vector<pair<int, int>>>(n+1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		road[a].push_back({ c,b });
	}
	cin >> a >> b; // a���� ����Ͽ� b����
	func(a, b);
	cout << ans << '\n' << cnt << '\n';
	for (auto a : path)
		cout << a << ' ';
    return 0;
}