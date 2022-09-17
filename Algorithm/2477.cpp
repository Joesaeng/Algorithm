// BOJ 2477 :: 참외밭
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int k, a, b;
int x, y; // 긴 가로 세로 길이
int xx, yy; // 짧은 가로 세로 길이
int cntx, cnty; // 가로 세로 인덱스
int dir[6]; // 방향 저장
int len[7]; // 길이 저장
int ans;
int main()
{
    FASTIO;
    cin >> k;
    for (int i = 0; i < 6; ++i)
    {
        cin >> a >> b; // a = 방향, b = 변의 길이
        len[i] = b;
        if (a == 1 || a == 2)
        {
            if (b > x)
            {
                x = b;
                cntx = i; // 가로로 가장 긴 변의 인덱스
            }
        }
        if (a == 3 || a == 4) 
        {
            if (b > y)
            {
                y = b;
                cnty = i; // 세로로 가장 긴 변의 인덱스
            }
        }
    }
    int sCntx = (cntx + 3) % 6;
    int sCnty = (cnty + 3) % 6;
    ans = ((x * y) - (len[sCntx] * len[sCnty])) * k;
    cout << ans;

    return 0;
}