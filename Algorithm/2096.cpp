// BOJ 2096 :: 내려가기
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int dpMin[2][3];
int dpMax[2][3];
int n, a, b, c;
int main()
{
    FASTIO;
    cin >> n;
    cin >> a >> b >> c;
    dpMin[0][0] = dpMax[0][0] = a;
    dpMin[0][1] = dpMax[0][1] = b;
    dpMin[0][2] = dpMax[0][2] = c;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;

        dpMax[1][0] = a + max(dpMax[0][0], dpMax[0][1]);
        dpMax[1][1] = b + max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
        dpMax[1][2] = c + max(dpMax[0][1], dpMax[0][2]);

        dpMax[0][0] = dpMax[1][0];
        dpMax[0][1] = dpMax[1][1];
        dpMax[0][2] = dpMax[1][2];

        dpMin[1][0] = a + min(dpMin[0][0], dpMin[0][1]);
        dpMin[1][1] = b + min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));
        dpMin[1][2] = c + min(dpMin[0][1], dpMin[0][2]);

        dpMin[0][0] = dpMin[1][0];
        dpMin[0][1] = dpMin[1][1];
        dpMin[0][2] = dpMin[1][2];

    }
    
    a = max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
    b = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));
    cout << a << ' ' << b;
    return 0;
}