// BOJ 1085 :: ���簢������ Ż��
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, w, h; cin >> x >> y >> w >> h;
	cout << min({ x ,w - x ,h - y , y });

	
	return 0;
}