// BOJ 5639 :: ���� �˻� Ʈ��
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int a;
int vec[10001];
int n, idx;
struct Node
{
    int key;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};
class Tree
{
public:
    void insert(int a)
    {
        Node* newNode = new Node();
        newNode->key = a;

        Node* node = root;
        Node* parent = nullptr;
        
        while (node != nullptr)
        {
            parent = node;
            if (a < node->key)
                node = node->left;
            else
                node = node->right;
        }
        newNode->parent = parent;

        if (parent == nullptr)
            root = newNode;
        else if (a < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    void postorder(Node* node)
    {
        if (node != nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << '\n';
        }

    }

public: 
    Node* root = nullptr;
};
void func(int left, int right)
{
    int cur = vec[idx++];
    if (vec[idx] < cur && vec[idx] > left) func(left, cur);
    if (vec[idx] > cur && vec[idx] < right) func(cur, right);
    cout << cur << '\n';
}
int main()
{
    FASTIO;
    /*Tree tree;
    while (cin >> a)
    {
        tree.insert(a);
    }
    tree.postorder(tree.root);*/
    while (cin >> vec[n++]);
    func(0, 1e7);
    return 0;
}

// ���� ��ȸ ������ ������ ���� ��ȸ ����� ����Ѵ�.
// ���� ��ȸ�� ��Ʈ��� -> ���ʳ�� -> �����ʳ��
// ���� ��ȸ�� ���ʳ�� -> �����ʳ�� -> ��Ʈ���