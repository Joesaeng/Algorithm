// BOJ 2638 :: ġ��
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m, cheez = 0;
int ans;
int vec[100][100];
bool vis[100][100];
queue<pair<int, int>> outQ;
queue<pair<int, int>> cq;
void outside()
{
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };
    while (!outQ.empty()) // �ܺ� Ž��
    {
        int y = outQ.front().first;
        int x = outQ.front().second;
        outQ.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (vis[ny][nx]) continue;
            vis[ny][nx] = true; // �ܺ� �����̰ų�, �̹� Ž������ ã�� ���̵�
            if (vec[ny][nx] == 1) cq.push({ ny,nx }); // ġ���� ġ��ť(cq)�� �ִ´�
            else outQ.push({ ny,nx });
        }
    }
    while (!cq.empty()) // ġ�� Ž��
    {
        int y = cq.front().first;
        int x = cq.front().second;
        int cnt = 0; // �ܺ� ����� �´��� ���� ��
        cq.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (vis[ny][nx] == true && vec[ny][nx] == 0) cnt++; // �ܺΰ���
        }
        if (cnt >= 2)
        {
            outQ.push({ y,x }); // ���� ġ����� �ܺ� ���Ⱑ �ȴ�.
            cheez--;            // �����Լ������� �ݺ����� ���� ġ�� ���� ����
        }
        else vis[y][x] = false; // ���� �ʾҴٸ� ������ ���� �湮�� ����Ѵ�
    }
    int qsize = outQ.size();
    for (int i = 0; i < qsize; ++i) // �̹��� ���� ġ����� ���̴� ����, ã�ڸ��� ���̰� �Ǹ� �̹� �Ͽ��� ���� �ʾƾ� �� ġ����� ��Եȴ�.
    {
        int y = outQ.front().first;
        int x = outQ.front().second;
        outQ.pop();
        vec[y][x] = 0;
        outQ.push({ y,x });
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 1) cheez++;
        }
    }
    outQ.push({ 0,0 });
    outQ.push({ 0,m-1 });
    outQ.push({ n-1,0 });
    outQ.push({ n-1,m-1 });
    vis[0][0] = vis[0][m - 1] = vis[n - 1][0] = vis[n - 1][m - 1] = true; // �� �𼭸����� Ž���� �����Ѵ� : 0,0���� �����ص� ������
    while (cheez > 0)
    {
        outside();
        ans++;
    }
   
    cout << ans;
    return 0;
}

// �����ڸ��� �ִ� ġ����� ã�´�.
// �� �߿� ���� ġ���(�ܺΰ���� 2���̻��� �´���ִ�)�� ã�´�.
// ���� ġ����� ���̰�, �̰� �ݺ�?