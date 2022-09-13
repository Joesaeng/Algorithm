// BOJ 24416 :: 알고리즘 수업 - 피보나치 수 1
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int f[50];
int a = 1, b = 0;
int fib(int n) 
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        a++;
        return (fib(n - 1) + fib(n - 2));
    }
}
int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        b++;
        f[i] = f[i - 1] + f[i - 2];
    }  
    return f[n];
}
int n;
int main()
{
	FASTIO;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << a << ' ' << b;

	return 0;
}