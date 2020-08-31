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

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
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

pair<int, int> LCA(Node* root , int first , int second ) {

    if (root == NULL ) return { -1 , 0 } ;

    if (root->data == first or root->data == second ) return  { root->data ,  1 } ;


    pair<int, int> leftAns = LCA(root->left , first , second ) ;
    pair<int, int> rightAns = LCA(root->right , first , second );

    if (leftAns, first != -1 and rightAns.first != -1  ) {
        return {root->data , abs(leftAns.second + 1 + rightAns.second )};
    }

    return leftAns.first == -1 ? leftAns : rightAns ;
}



int NumberOFTurns(struct Node* root, int first, int second)
{
    // Your code goes here

    pair<int, int> ans = LCA(root, first, second);

    if (ans.first == first or ans.first == second ) return -1 ;

    else return ans.second;
}

// { Driver Code Starts.

int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin >> first >> second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout << turn << endl;
        else
            cout << "-1\n";
        cin.ignore();
    }
    return 0;
}
// } Driver Code Ends