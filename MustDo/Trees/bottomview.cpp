// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

Node* buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

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



int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s , ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

map < int , vector<int> > verticalOrder(Node *root)
{

    queue<pair<Node* , int > > qu ;

    qu.push(make_pair(root, 0));

    map < int , vector<int> > traversals ;
    while (!qu.empty()) {
        pair<Node*, int> fr = qu.front();
        qu.pop();
        Node* cur = fr.first;
        int cord = fr.second;
        traversals[cord].push_back(cur->data);
        if (cur->left != NULL) {
            qu.push(make_pair(cur->left , cord - 1));
        }
        if (cur->right != NULL  ) {
            qu.push(make_pair(cur->right , cord + 1));
        }

    }

    map<int, vector<int> > ::iterator it ;


    return traversals;
}


vector <int> bottomView(Node *root)
{
    map<int, vector<int> > res = verticalOrder(root);

    vector<int> bottom;
    for (auto i : res ) {
        // cout << i.second[i.second.size() - 1] << " ";
        bottom.push_back(i.second[i.second.size() - 1]);
    }

    return bottom;
}

