// BOJ 0 ::
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
int main()
{
    FASTIO;
    ll n, f;
    cin >> n >> f;
    n /= 100; // ���� �ڿ� ���ڸ��� ������ �ٲپ�� �ϱ� ������
    n *= 100; // ���� �ڿ� ���ڸ��� 00���� �������´�.
    while (n % f != 0) // ������ ������ ������
    {
        n++; // n�� 00���� 1�� ���ϸ鼭 �ݺ����� ������
    }
    if (n % 100 >= 10)
        cout << n % 100;
    else
        cout << "0" << n % 100; // ���ڸ����϶� �տ� 0�� �ٿ��ֱ�
    
    return 0;
}