// BOJ 1005 :: ACM Craft
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t;
int n, k, w;
vector<int> delay;          // i��° �ǹ��� ���µ� �ɸ��� �ð�
vector<vector<int>> road;   // �ǹ��� ���� ��Ģ
vector<int> resT;           // i��° �ǹ��� ���µ� �ɸ��� �ð�
vector<int> entry;          // i��° �ǹ��� ���µ� �ʿ��� �ǹ� ����
int func(int dest)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (entry[i] == 0) // i��° �ǹ��� ���µ� �ʿ��� �ǹ��� ���� ��
        {
            q.push(i); // ť�� �־��ְ�
            resT[i] = delay[i]; // i��° �ǹ��� ���µ� �ɸ��� �ð�
        }
    }
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        for (int i = 0; i < road[pos].size(); ++i)
        {
            int next = road[pos][i];
            // ���� �ǹ��� ���� ���� �ʿ��� �ð��� ���� �ǹ��� �������� �ʿ���
            // �ǹ��� ���� �����ɸ��� �ǹ��� �������µ� �ɸ��� �ð��̱� ������
            // �ִ밪���� �������ش�.
            resT[next] = max(resT[next], resT[pos] + delay[next]); 
            entry[next]--; // ���� �ǹ��� ���µ� �ʿ��� �ǹ��� ���� ���Ѵ�.
            if (entry[next] == 0) q.push(next); // ���� �ǹ��� ���� �� �ִٸ� ť�� �־��ش�.
        }
    }
    return resT[dest];
}
int main()
{
    FASTIO;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        delay = vector<int>(n + 1);
        road = vector<vector<int>>(n + 1);
        resT = vector<int>(n + 1);
        entry = vector<int>(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> delay[i];
        }
        for (int i = 0; i < k; ++i)
        {
            int a, b;
            cin >> a >> b;
            road[a].push_back(b);
            entry[b]++;
        }
        cin >> w;
        cout << func(w) << '\n';
    }
    return 0;
}