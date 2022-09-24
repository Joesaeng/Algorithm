// BOJ 10026 :: 적록색약
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
string str[100];
bool visRB[100][100];
bool visRGB[100][100];
int cntrb, cntrgb;
void BFSrb(int y, int x,int color)
{
    queue<pair<int, int>> q;
    int py = y;
    int px = x;
    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };
    q.push(pair{ py,px });
    visRB[py][px] = true;
    while (!q.empty())
    {
        py = q.front().first;
        px = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = py + dy[i];
            int nx = px + dx[i];
            if (ny < 0 || ny >= n || nx <0 || nx >= n) continue;
            if (visRB[ny][nx]) continue;
            int c = str[ny][nx] == 'R' || str[ny][nx] == 'G' ? 0 : 1;
            if (c != color) continue;
            q.push(pair{ ny,nx });
            visRB[ny][nx] = true;
        }
    }
}
void BFSrgb(int y, int x, int color)
{
    queue<pair<int, int>> q;
    int py = y;
    int px = x;
    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };
    q.push(pair{ py,px });
    visRGB[py][px] = true;
    while (!q.empty())
    {
        py = q.front().first;
        px = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = py + dy[i];
            int nx = px + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visRGB[ny][nx]) continue;
            int c = str[ny][nx] == 'R' ? 0 : str[ny][nx] == 'G' ? 1 : 2;
            if (c != color) continue;
            q.push(pair{ ny,nx });
            visRGB[ny][nx] = true;
        }
    }
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
           if (!visRB[i][j])
           {
               int color = str[i][j] == 'R' || str[i][j] == 'G' ? 0 : 1;
               BFSrb(i, j,color);
               cntrb++;
           }
           if (!visRGB[i][j])
           {
               int color = str[i][j] == 'R' ? 0 : str[i][j] == 'G' ? 1 : 2;
               BFSrgb(i, j, color);
               cntrgb++;
           }
        }
    }
    cout << cntrgb << ' ' << cntrb;
    return 0;
}