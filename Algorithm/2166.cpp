// BOJ 2166 :: 다각형의 면적
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
double x, y,fx,fy;
double ans = 0;
vector<pair<double, double>> vec;
double shoelace(int n,vector<pair<double, double>>& points)
{
    double ret;
    double fx = points[0].first;
    double fy = points[0].second;
    double aa = 0;
    double bb = 0;
    for (int i = 0; i < n-1; ++i)
    {
        double a = points[i].first * points[i + 1].second;
        double b = points[i].second * points[i + 1].first;
        aa += a;
        bb += b;
    }
    double a = points[n - 1].first * fy;
    double b = points[n - 1].second * fx;
    aa += a;
    bb += b;

    ret = abs(aa - bb) / 2;

    return ret;
}
int main()
{
    FASTIO;
    cin >> n;
    vec = vector<pair<double, double>>(n);
    cout << fixed;
    cout.precision(1);
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        vec[i].first = x;
        vec[i].second = y;
    }
    ans = shoelace(n, vec);
    cout << ans;

    return 0;
}