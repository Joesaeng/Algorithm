// BOJ 2250 :: 트리의 높이와 너비
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 10000 + 1
int n;
using namespace std;
struct Node
{
	int left = -1;
	int right = -1;
};
vector<Node> tree(MAX);
vector<int> parent(MAX,0);
vector<int> mincol(MAX,INT32_MAX);
vector<int> maxcol(MAX);
int maxLev = 1;
int col = 1;
int ansLev = 0, ansLen = 0;

void func()
{

}

void inorderTrav(int cur,int lv) // 중위 순회
{
	maxLev = maxLev > lv ? maxLev : lv; // 최대 레벨 찾기(나중 반복문을 위함)
	if (tree[cur].left != -1) inorderTrav(tree[cur].left, lv + 1);

	mincol[lv] = min(mincol[lv], col); 
	maxcol[lv] = max(maxcol[lv], col); // 현재 레벨에서 최소 열과 최대 열을 찾음
	col++; 

	if (tree[cur].right != -1) inorderTrav(tree[cur].right, lv + 1);
}
int main()
{
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b != -1)
		{
			tree[a].left = b;
			parent[b] = a;
		}
		if (c != -1)
		{
			tree[a].right = c;
			parent[c] = a;
		}
	}
	int root = 1;
	while (parent[root] != 0)
	{
		root = parent[root];
	}
	inorderTrav(root, 1);
	int temp;
	for (int i = 1; i <= maxLev; ++i)
	{
		temp = maxcol[i] - mincol[i] + 1;
		if (ansLen < temp)
		{
			ansLev = i;
			ansLen = temp;
		}
	}
	cout << ansLev << ' ' << ansLen;


	return 0;
}