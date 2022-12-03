// BOJ 2263 :: Ʈ���� ��ȸ
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
int in[100001]; // �ο��� | inoder (������ȸ) �����ڽĳ�� -> ��Ʈ��� -> �������ڽĳ��
int post[100001]; // ����Ʈ���� | postorder (������ȸ) �����ڽĳ�� -> �������ڽĳ�� -> ��Ʈ���
int idx[100001];
// �������� | preoder (������ȸ) ��Ʈ��� -> �����ڽĳ�� -> �������ڽĳ��
void func(int inS, int inE, int postS, int postE) 
{
    if (inS > inE || postS > postE)
        return;
    int rootIndex = idx[post[postE]]; // �ο��������� ��Ʈ�� �ε���
    int leftSize = rootIndex - inS; // ���� ����� ����
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