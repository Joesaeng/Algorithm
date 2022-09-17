// BOJ 3009 :: 네 번째 점
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
    FASTIO;
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int x = x1 == x2 ? x3 : x1 == x3 ? x2 : x1;
    int y = y1 == y2 ? y3 : y1 == y3 ? y2 : y1;
    cout << x << ' ' << y;
    
    return 0;
}