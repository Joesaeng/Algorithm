// BOJ 10997 :: º° Âï±â 22
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 400 + 1
using namespace std;
int N;
char board[MAX][MAX];
void star(int y, int x, int n)
{
    if (n == 1)
    {
        board[y][x] = '*';
        return;
    }
    if (n == 2)
    {
        board[y+2][x + (4 * (n-1))/2] = board[y + 3][x + (4 * (n - 1)) / 2] = board[y + 4][x + (4 * (n - 1)) / 2] = '*';
    }
    for (int i = 0; i < 4 * n - 1; ++i)
    {
        if (i == 0 || i == 4 * n - 2)
        {
            for (int j = 0; j < 4 * (n - 1) + 1; ++j)
            {
                board[y + i][x + j] = '*';
            }
        }
        if (i == 2) board[y + i][x] = board[y + i][x + 4 * (n - 1)] = board[y + i][x + 4 * (n - 1) - 1] = '*';
        if (i == 1) board[y + i][x] = '*';
        else
        {
            board[y + i][x] = board[y + i][x + 4 * (n - 1)] = '*';
        }
    }
    star(y + 2, x + 2, n - 1);
}
int main()
{
    FASTIO;
    cin >> N;
    if (N != 1)
    {
        star(0, 0, N);
        for (int i = 0; i < 4 * N - 1; ++i)
        {
            if (i == 1)
            {
                cout << "*\n";
                continue;
            }
            for (int j = 0; j < 4 * (N - 1) + 1; ++j)
            {
                char c = board[i][j] == '*' ? '*' : ' ';
                cout << c;
            }
            cout << '\n';
        }
    }
    else cout << '*';
    return 0;
}
