// BOJ 2477 :: ���ܹ�
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int k, a, b;
int x, y; // �� ���� ���� ����
int xx, yy; // ª�� ���� ���� ����
int cntx, cnty; // ���� ���� �ε���
int dir[6]; // ���� ����
int len[7]; // ���� ����
int ans;
int main()
{
    FASTIO;
    cin >> k;
    for (int i = 0; i < 6; ++i)
    {
        cin >> a >> b; // a = ����, b = ���� ����
        len[i] = b;
        if (a == 1 || a == 2)
        {
            if (b > x)
            {
                x = b;
                cntx = i; // ���η� ���� �� ���� �ε���
            }
        }
        if (a == 3 || a == 4) 
        {
            if (b > y)
            {
                y = b;
                cnty = i; // ���η� ���� �� ���� �ε���
            }
        }
    }
    int sCntx = (cntx + 3) % 6;
    int sCnty = (cnty + 3) % 6;
    ans = ((x * y) - (len[sCntx] * len[sCnty])) * k;
    cout << ans;

    return 0;
}