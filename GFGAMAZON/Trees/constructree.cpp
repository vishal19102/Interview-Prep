// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int inorder[n], preorder[n];
		for (int i = 0; i < n; i++)
			cin >> inorder[i];
		for (int i = 0; i < n; i++)
			cin >> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout << endl;
	}
}

Node* buildTree(int in[], int pre[], int n)
{
//add code here.
	Node* root = buildTree()
}