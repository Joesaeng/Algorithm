// BOJ 2630 :: 색종이 만들기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int k;
int blue = 0, white = 0;
vector<vector<int>> paper;
void cut(int startY,int startX,int n)
{
    bool b = true;
    bool w = true;
    for (int i = startY; i < startY + n; ++i)
    {
        for (int j = startX; j < startX + n; ++j)
        {
            if (!b && !w) break;
            if (paper[i][j] != 1)
            {
                b = false;
            }
            if (paper[i][j] != 0)
            {
                w = false;
            }
        }
   }
    if (b)
    {
        blue++;
        return;
    }
    else if(w)
    {
        white++;
        return;
    }
    else
    {
        cut(startY, startX, n / 2);
        cut(startY, startX + (n/2), n / 2);
        cut(startY + (n / 2), startX, n / 2);
        cut(startY + (n / 2), startX + (n / 2), n / 2);
    }
}

int main()
{
    FASTIO;
    cin >> k;
    paper = vector<vector<int>>(k+1, vector<int>(k+1));
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> paper[i][j];
        }
    }
    cut(0, 0, k);
    cout << white << '\n' << blue;
    return 0;
}