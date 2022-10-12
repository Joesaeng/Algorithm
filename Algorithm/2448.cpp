// BOJ 2448 :: º° Âï±â 11
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int N;
char board[3073][6145];
void star(int y, int x, int n)
{
    if (n == 1)
    {
        int c = '*';
        board[y][x] = c;
        board[y + 1][x - 1] = board[y + 1][x + 1] = c;
        board[y + 2][x - 2] = board[y + 2][x - 1] = board[y + 2][x] = board[y + 2][x + 1] = board[y + 2][x + 2] = c;
        return;
    }
    star(y, x,n/2);
    star(y + 3*n/2, x - 3*n/2,n/2);
    star(y + 3*n/2, x + 3*n/2,n/2);
}
int main()
{
    FASTIO;
    cin >> N;
    int k = N/3;
    star(1, N, k);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 2 * N - 1; ++j)
        {
            char c = board[i][j] == '*' ? '*' : ' ';
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}