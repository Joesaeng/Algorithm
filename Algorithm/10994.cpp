// BOJ 10994 :: º°Âï±â 19
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 400 + 1
using namespace std;
int N;
char board[MAX][MAX];
void star(int y, int x,int n)
{
    if (n == 1)
    {
        board[y][x] = '*';
        return;
    }
    for (int i = 0; i < 4 * (n - 1) + 1; ++i)
    {
        if (i == 0 || i == 4 * (n - 1))
        {
            for (int j = 0; j < 4 * (n - 1) + 1; ++j)
            {
                board[y + i][x + j] = '*';
            }
        }
        board[y + i][x] = '*';
        board[y + i][x + 4 * (n - 1)] = '*';
    }
    star(y + 2, x + 2, n - 1);

}
int main()
{
    FASTIO;
    cin >> N;
    star(0,0,N);
    for (int i = 0; i < 4 * (N - 1) + 1; ++i)
    {
        for (int j = 0; j < 4 * (N - 1) + 1; ++j)
        {
            char c = board[i][j] == '*' ? '*' : ' ';
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}