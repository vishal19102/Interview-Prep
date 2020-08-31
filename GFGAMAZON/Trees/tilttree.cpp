// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

int tiltTree(Node* root);

int main()
{
  int t;
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  scanf("%d", &t);
  while (t--)
  {
    map<int, Node*> m;
    int n;
    scanf("%d", &n);
    struct Node *root = NULL;
    struct Node *child;
    while (n--)
    {
      Node *parent;
      char lr;
      int n1, n2;
      scanf("%d %d %c", &n1, &n2, &lr);
      if (m.find(n1) == m.end())
      {
        parent = new Node(n1);
        m[n1] = parent;
        if (root == NULL)
          root = parent;
      }
      else
        parent = m[n1];
      child = new Node(n2);
      if (lr == 'L')
        parent->left = child;
      else
        parent->right = child;
      m[n2]  = child;
    }
    cout << tiltTree(root) << endl;
  }
  return 0;
}
// Contributed by: Harshit Sidhwa
// } Driver Code Ends

int totalTilt;

int tilt(Node* root ) {
  if (root == NULL ) return 0 ;

  if (root->left == NULL and root->right == NULL ) return root->val;

  int leftTilt = tilt(root->left);
  int rightTilt = tilt(root->right);

  int curr_tilt = leftTilt - rightTilt ;

  totalTilt += abs(curr_tilt);

  return leftTilt + rightTilt + root->val;
}


int tiltTree(Node* root)
{
  // Code here
  totalTilt = 0 ;
  tilt(root);
  return totalTilt ;

}