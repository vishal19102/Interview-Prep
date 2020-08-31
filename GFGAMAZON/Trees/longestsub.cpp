// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int longestConsecutive(Node* root);

int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << longestConsecutive(root) << endl;
    }
    return 0;
}
int max_length = -1 ;

int pahtmax(Node* root ) {
    if (root == NULL ) return 0 ;

    int leftMax = pahtmax(root->left);
    int rightMax = pahtmax(root->right);

    int cur_max = 0 ;
    bool Left = false , Right = false  ;

    if (root->left) {
        if ( (root->data -  root->left->data) == 1 ) {
            Left = true ;
        }
    }
    if (root->right) {
        if ( ( root->right->data - root->data ) == 1 ) {
            Right = true ;
        }
    }

    if (Left and Right ) {
        cur_max = leftMax + rightMax  + 1 ;
    }
    if (Left ) cur_max = leftMax + 1 ;
    if (Right ) cur_max = rightMax + 1 ;

    max_length = max(max_length , cur_max ) ;

    int ret_val =  max(leftMax , rightMax) ;
    return ret_val;
}


int longestConsecutive(Node* root)
{
    //Code here

    return max_length ;
}