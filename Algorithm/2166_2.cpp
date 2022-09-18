// BOJ 2166 :: �ٰ����� ����
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
    cin >> fx >> fy; // ù��° ��
    cin >> x >> y; // �ι�° ��
    q.push(pair{ x,y });
    for (int i = 2; i < n; ++i)
    {
        cin >> x >> y; // ������ ��
        q.push(pair{ x,y }); // ������ ���� ť�� �־���
        pair<double, double> temp1 = q.front(); // �ι�° ���� ����
        q.pop(); // ����
        pair<double, double> temp2 = q.front(); // �̹��� �־��� ������ ��
        double len1 = length(fx, fy, temp1.first, temp1.second); // ù��° ���� ������ ������� ������ ����
        double len2 = length(fx, fy, temp2.first, temp2.second); // ù��° ���� �̹��� ���� ������ ����
        double len3 = length(temp1.first, temp1.second, temp2.first, temp2.second); // ������ ���� �̹��� ������ ����
        double temp = Heron(len1, len2, len3); // ����� ����
        ans += temp;
    }
    cout << ans;

    return 0;
}