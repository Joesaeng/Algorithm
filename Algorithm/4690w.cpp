// BOJ 4690 :: 완전 세제곱
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void func(int start)
{
    for (int i = 2; i < start; ++i)
    {
        for (int j = i; j < start; ++j)
        {
            for (int k = j; k < start; ++k)
            {
                if (i * i * i + j * j * j + k * k * k == start * start * start)
                {
                    cout << "Cube = " << start << ", Triple = (" << i << ',' << j << ',' << k << ")\n";
                }
            }
        }
    }
}
int main()
{
    FASTIO;
    for (int i = 6; i <= 100; ++i)
    {
        func(i);
    }
    return 0;
}