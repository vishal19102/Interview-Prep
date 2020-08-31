// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void printInorder (struct Node* node)
{
    if (node == NULL)
        return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}


Node*  binaryTreeToBST (Node *root);


void inOrderBT(Node* root , vector<int> &travers ) {

    if (root == NULL ) return ;

    inOrderBT(root->left , travers );
    travers.push_back(root->data);
    inOrderBT(root->right , travers );

    return ;

}

void updateBT(Node* root , deque<int> & traver2 ) {

    if (root == NULL ) return ;

    updateBT(root->left, traver2 ) ;
    root->data = traver2.front();
    traver2.pop_front();
    updateBT(root->right, traver2);
}

Node *binaryTreeToBST (Node *root)
{
    if (root == NULL ) return NULL ;

    vector<int> traver1 ;
    inOrderBT(root , traver1) ;
    deque<int> traver2 (traver1.begin(), traver1.end());
    sort(traver2.begin(), traver2.end()) ;

    updateBT(root , traver2 ) ;

    return root ;
}

int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Node *res = binaryTreeToBST (root);
        printInorder(res);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends