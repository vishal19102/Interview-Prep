// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
int minTime(Node* root, int target) ;


// { Driver Code Starts.


int main()
{
    int tc;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        cout << minTime(root, target) << "\n";

        cin.ignore();

    }


    return 0;
}
int maxDepth(Node* root ) {

    if (root == NULL ) return 0 ;

    int leftAns = maxDepth(root->left);
    int rightAns = maxDepth(root->right);

    return max(leftAns, rightAns ) + 1 ;
}


int ans = 0 ;
// } Driver Code Ends
int burnTree(Node * root , int target ) {

    if (root == NULL ) return  0 ;

    if (root->data == target ) return 1 ;

    int ansLeft = burnTree(root->left, target)   ;

    int ansRight = burnTree(root->right, target )  ;


    if (ansLeft != 0  ) {
        ansLeft += 1 ;
        int md = maxDepth(root->right);
        ans = max(md + ansLeft, ans) ;
        return ansLeft;
    }
    else if (ansRight != 0) {
        ansRight += 1 ;
        int md = maxDepth(root->right);
        ans = max(md + ansRight, ans);
        return ansRight;
    }
    else return 0;
}



int minTime(Node* root, int target)
{
    // Your code goes here
    if (root == NULL or root->data == target ) return 0 ;

    burnTree(root , target);

    return ans ;
}


