// BOJ 17144 :: �̼����� �ȳ�!
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
pair<int, int> topAir;
pair<int, int> downAir; // ����û���� ��ġ
bool bTop;
int r, c, t;// r*c ��� t��
struct Pos
{
    int y = 0;
    int x = 0;
    int dust = 0; // ��ǥ�� �� ��ǥ�� �ִ� ������ ��
};
vector<vector<int>> vec;
queue<Pos> q;
void func()
{
    int tempT = 0;
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };
    while (tempT < t) // t�ʰ� ���������� ����û���⸦ ������
    {
        while (!q.empty()) // �̼����� Ȯ��
        {
            Pos pos = q.front();
            int cnt = 0;
            q.pop();
            for (int i = 0; i < 4; ++i) // �� �������� ������ Ȯ���Ѵ�
            {
                int nexty = pos.y + dy[i];
                int nextx = pos.x + dx[i];
                if (nexty < 0 || nexty >= r || nextx < 0 || nextx >= c) continue;
                if (vec[nexty][nextx] == -1) continue; // Ȯ�� �������� üũ
                vec[nexty][nextx] += pos.dust / 5; // Ȯ��!
                cnt++; // Ȯ���� ����
            }
            vec[pos.y][pos.x] -= pos.dust / 5 * cnt; // Ȯ���Ų��ŭ ������ġ�� ������ ���� �ٿ���
        }
        vec[topAir.first - 1][0] = 0; // ����û���� �ٷ� ��
        // �� �������� �о��ִ� �ϵ��ڵ�
        for (int i = topAir.first - 2; i >= 0; --i)
        {
            vec[i+1][0] = vec[i][0];
        }
        for (int i = 0; i < c - 1; ++i)
        {
            vec[0][i] = vec[0][i + 1];
        }
        for (int i = 0; i < topAir.first; ++i)
        {
            vec[i][c - 1] = vec[i + 1][c - 1];
        }
        for (int i = c - 1; i > 1; --i)
        {
            vec[topAir.first][i] = vec[topAir.first][i - 1];
        } 
        vec[topAir.first][1] = 0; // �о������� ����û���� �ٷξ��� ������ ����
        vec[downAir.first + 1][0] = 0; // ����û���� �ٷ� ��
        // �� �������� �о��ִ� �ϵ��ڵ�
        for (int i = downAir.first +2 ; i < r; ++i)
        {
            vec[i - 1][0] = vec[i][0];
        }
        for (int i = 0; i < c - 1; ++i)
        {
            vec[r-1][i] = vec[r-1][i + 1];
        }
        for (int i = r - 1; i > downAir.first; --i)
        {
            vec[i][c - 1] = vec[i - 1][c - 1];
        }
        for (int i = c - 1; i > 1; --i)
        {
            vec[downAir.first][i] = vec[downAir.first][i - 1];
        }
        vec[downAir.first][1] = 0; // �о������� ����û���� �ٷξ��� ������ ����

        // ����û���⸦ 1�� ���� ���� ���� �������� üũ�ؼ� �ٽ� ť�� �־��ش�
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (vec[i][j] != -1 && vec[i][j] != 0)
                    q.push({ i,j,vec[i][j] });
            }
        }
        tempT++; // 1��
    }
}
int main()
{
    FASTIO;
    cin >> r >> c >> t;
    vec = vector<vector<int>>(r, vector<int>(c,0));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> vec[i][j];
            if (vec[i][j] < 0)
            {
                if (!bTop)  // ����û����� ���Ʒ��� �پ��ְ�, 
                            // �Է� Ư���� ����û������ ����ĭ�� ���� ���ü��ۿ� ������ �Ұ��� �ϳ� ��������
                {
                    topAir = { i,j };
                    bTop = true;
                }
                else downAir = { i,j };
            }
            else if (vec[i][j] != 0)
            {
                q.push({ i,j,vec[i][j] }); // ������ ������ �ֱ�
            }
        }
    }
    func();
    int ans = 0;
    while (!q.empty()) // func�� ���� ť���� ���� �������� ����ִ�.
    {
        ans += q.front().dust;
        q.pop();
    }
    cout << ans;
    return 0;
}