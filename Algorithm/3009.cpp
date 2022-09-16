// BOJ 3009 :: 네 번째 점
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int vecx[3];
int vecy[3];
int a, b;
int main()
{
    FASTIO;
    int x = 0, y = 0;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a >> b;
        vecx[i] = a;
        vecy[i] = b;
    }
    
    return 0;
}