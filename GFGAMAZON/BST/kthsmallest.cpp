// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};


int KthSmallestElement(Node *root, int k);

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
  Node* root = new Node(stoi(ip[0]));

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
    string s;
    getline(cin, s);
    Node* root = buildTree(s);

    getline(cin, s);
    int k = stoi(s);
    //  getline(cin, s);

    cout << KthSmallestElement(root, k) << endl;
    //cout<<"~"<<endl;
  }
  return 0;
}// } Driver Code Ends


/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the Kth smallest element in the given BST

int req_k = 0 ;
int smallest = -1 ;
void KthSmallestElement(Node* root ) {

  if (root == NULL ) return ;

  KthSmallestElement(root->left);

  if (req_k == 1) smallest = root->data;
  req_k--;

  KthSmallestElement(root->right);

}

int KthSmallestElement(Node *root, int K)
{
  //add code here.
  req_k = K ;
  smallest = -1 ;
  KthSmallestElement(root);
  return smallest;
}