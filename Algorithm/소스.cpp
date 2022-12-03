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
    n /= 100; // 가장 뒤에 두자리를 적절히 바꾸어야 하기 때문에
    n *= 100; // 가장 뒤에 두자리는 00으로 만들어놓는다.
    while (n % f != 0) // 나누어 떨어질 때까지
    {
        n++; // n을 00부터 1씩 더하면서 반복문을 돌려줌
    }
    if (n % 100 >= 10)
        cout << n % 100;
    else
        cout << "0" << n % 100; // 한자리수일때 앞에 0을 붙여주기
    
    return 0;
}