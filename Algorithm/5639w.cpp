// BOJ 5639 :: 이진 검색 트리
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int a;
int vec[10001];
int n, idx;
// 나는 트리를 직접 클래스로 구현해서 풀이를 했는데 시간이 152ms가 나왔다
// 그래서 다른사람들 0ms로 나온 풀이를 보니 훨씬 빠르고 간단해 보였다
// 그런데 다시 풀라고 해도 트리를 구현해서 풀었을것 같다
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

// 전위 순회 순서가 들어오면 후위 순회 결과를 출력한다.
// 전위 순회는 루트노드 -> 왼쪽노드 -> 오른쪽노드
// 후위 순회는 왼쪽노드 -> 오른쪽노드 -> 루트노드