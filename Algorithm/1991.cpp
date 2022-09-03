// BOJ 1991 :: 트리 순회
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
char a, b, c;

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	char key;
};
Node* parent = nullptr;
class Tree
{
public:
	void search(Node* node, char key)
	{
		if (node && node->key == key)
		{
			parent = node;
			return;
		}
		if (node && node->left)
			search(node->left, key);
		if (node && node->right)
			search(node->right, key);
	}
	void insert(char a,char b, char c)
	{
		if (root == nullptr)
		{
			Node* newNode = new Node();
			root = newNode;
			root->key = a;
		}
		search(root, a);
		if (b != '.')
		{
			Node* newNode = new Node();
			parent->left = newNode;
			newNode->parent = parent;
			newNode->key = b;
		}
		if (c != '.')
		{
			Node* newNode = new Node();
			parent->right = newNode;
			newNode->parent = parent;
			newNode->key = c;
		}
	}
	void print()
	{
		print_in(root);
		cout << '\n';
		print_pre(root);
		cout << '\n';
		print_post(root);
		cout << '\n';
	}
	void print_in(Node* node)
	{
		if (node == nullptr) return;
		cout << node->key;
		print_in(node->left);
		print_in(node->right);
	}
	void print_pre(Node* node)
	{
		if (node == nullptr) return;
		print_pre(node->left);
		cout << node->key;
		print_pre(node->right);
		
	}
	void print_post(Node* node)
	{
		if (node == nullptr) return;
		print_post(node->left);
		print_post(node->right);
		cout << node->key;
	}

private:
	Node* root = nullptr;
};

int main()
{
	FASTIO;
	cin >> n;
	Tree tree;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		tree.insert(a, b, c);
	}
	tree.print();
	return 0;
}