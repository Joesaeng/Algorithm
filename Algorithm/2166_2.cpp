// BOJ 2166 :: 다각형의 면적
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
double x, y, fx, fy;
double ans = 0;
queue<pair<double, double>> q;
double Heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double ret = sqrt(s * (s - a) * (s - b) * (s - c));
    return ret;
}
double length(double x, double y, double xx, double yy)
{
    double ret = 0;
    ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
    return ret;
}
int main()
{
    FASTIO;
    cin >> n;
    cout << fixed;
    cout.precision(1);
    cin >> fx >> fy; // 첫번째 점
    cin >> x >> y; // 두번째 점
    q.push(pair{ x,y });
    for (int i = 2; i < n; ++i)
    {
        cin >> x >> y; // 마지막 점
        q.push(pair{ x,y }); // 마지막 점을 큐에 넣어줌
        pair<double, double> temp1 = q.front(); // 두번째 점을 꺼냄
        q.pop(); // 꺼냄
        pair<double, double> temp2 = q.front(); // 이번에 넣어준 마지막 점
        double len1 = length(fx, fy, temp1.first, temp1.second); // 첫번째 점과 이전에 만들어진 점과의 길이
        double len2 = length(fx, fy, temp2.first, temp2.second); // 첫번째 점과 이번에 만든 점과의 길이
        double len3 = length(temp1.first, temp1.second, temp2.first, temp2.second); // 이전의 점과 이번에 점과의 길이
        double temp = Heron(len1, len2, len3); // 헤론의 공식
        ans += temp;
    }
    cout << ans;

    return 0;
}