// BOJ 3053 :: 택시 기하학
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.14159265358979323846
using namespace std;
int r;
double ucl, taxi;
int main()
{
    FASTIO;
    cin >> r;
    cout << fixed;
    cout.precision(6);
    ucl = PI * r * r;
    taxi = 2 * r * r;
    cout << ucl << '\n' << taxi;
    return 0;
}