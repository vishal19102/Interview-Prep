// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if (!n) return 1;
    if ( n->data <= lower || n->data >= upper ) return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int, bool> isBalanced(Node* n)
{
    if (!n) return pair<int, bool> (0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if ( abs(l.first - r.first) > 1 ) return pair<int, bool> (0, 0);

    return pair<int, bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
    if ( !isBST(root, INT_MIN, INT_MAX) )
        cout << "BST voilated, inorder traversal : ";

    else if ( ! isBalanced(root).second )
        cout << "Unbalanced BST, inorder traversal : ";

    else return 1;
    return 0;
}

void printInorder(Node* n)
{
    if (!n) return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
    int ip[MAXN];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> ip[i];

        Node* root = NULL;

        for (int i = 0; i < n; i++)
        {
            root = insertToAVL( root, ip[i] );

            if ( ! isBalancedBST(root) )
                break;
        }

        printInorder(root);
        cout << endl;
    }
    return 0;
}
int height(Node* root ) {

    if (root == NULL ) return 0 ;
    else return root->height;
}


Node* leftRotate(Node* root ) {

    Node* oldRight = root->right;
    Node* newRight = root->right->left;

    oldRight->left = root;
    root->right = newRight;


    root->height = max(height(root->left) , height(root->right) ) + 1;

    oldRight->height = max(height(oldRight->left), height(oldRight->right) ) + 1 ;

    return oldRight;
}



Node* rightRotate(Node* root ) {

    Node* oldLeft = root->left;
    Node* newLeft = root->left->right;

    oldLeft->right = root ;
    root->left = newLeft;


    root->height = max(height(root->left) , height(root->right)) + 1;

    oldLeft->height = max(height(oldLeft->left) , height(oldLeft->right) ) + 1 ;

    return oldLeft;
}


Node* insertToAVL(Node* node, int data)
{
    if (node == NULL ) {
        return new Node(data);
    }

    if (node->data > data ) {
        node->left  =   insertToAVL(node->left , data);
    }
    else {
        node->right = insertToAVL(node->right , data );
    }



    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    node->height = 1 + max(leftHeight , rightHeight);

    int balance = leftHeight - rightHeight  ;


    if (balance > 1 and node->left->data > data ) {
        return rightRotate(node);
    }

    if (balance > 1 and node->left->data < data ) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1  and node->right->data < data ) {
        return leftRotate(node);
    }

    if (balance < -1 and node->right->data > data ) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node ;
}