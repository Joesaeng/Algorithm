// BOJ 1085 :: 직사각형에서 탈출
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, w, h; cin >> x >> y >> w >> h;
	cout << min({ x ,w - x ,h - y , y });

	
	return 0;
}