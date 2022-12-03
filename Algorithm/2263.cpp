// BOJ 2263 :: 트리의 순회
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int in[100001]; // 인오더 | inoder (중위순회) 왼쪽자식노드 -> 루트노드 -> 오른쪽자식노드
int post[100001]; // 포스트오더 | postorder (후위순회) 왼쪽자식노드 -> 오른쪽자식노드 -> 루트노드
int idx[100001];
// 프리오더 | preoder (전위순회) 루트노드 -> 왼쪽자식노드 -> 오른쪽자식노드
void func(int inS, int inE, int postS, int postE) 
{
    if (inS > inE || postS > postE)
        return;
    int rootIndex = idx[post[postE]]; // 인오더에서의 루트의 인덱스
    int leftSize = rootIndex - inS; // 왼쪽 노드의 개수
    cout << in[rootIndex] << ' ';

    func(inS, rootIndex - 1, postS, postS + leftSize - 1);
    func(rootIndex + 1, inE, postS + leftSize, postE - 1);
}
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> in[i];
        idx[in[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> post[i];
    }
    func(1, n, 1, n);
    return 0;
}