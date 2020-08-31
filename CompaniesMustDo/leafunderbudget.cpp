// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};

int getCount(struct node* node, int k);

int main()
{
  int t;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  struct node *child;
  scanf("%d\n", &t);
  while (t--)
  {
    map<int, node*> m;
    int n;
    scanf("%d\n", &n);
    struct node *root = NULL;
    if (n == 1)
    {
      int a;
      cin >> a;
      cout << a << endl;
    } else {
      while (n--)
      {
        node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
          parent = new node(n1);
          m[n1] = parent;
          if (root == NULL)
            root = parent;
        }
        else
          parent = m[n1];

        child = new node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
      }
      int tmp;
      cin >> tmp;
      cout << getCount(root, tmp) << endl;
    }
  }
  return 0;
}
// } Driver Code Ends


/*
Structure of the node of the binary tree is as
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
*/
// your are required to complete this function
// function should return the number of leaf node
// one can visit
int getCount(struct node* node, int k)
{
  // Code here
  int budget = k ;
  queue<struct node*> qu ;
  qu.push(node);
  qu.push(NULL);
  int level = 1;
  int count = 0 ;
  while ( !qu.empty()) {

    struct node* fr = qu.front();
    qu.pop();

    if (fr == NULL ) {
      if (!qu.empty()) {
        qu.push(NULL);
        level++;
      }
    }
    else {
      if (fr->left == NULL and fr->right == NULL && (budget - level) > 0 ) {
        count++;
        budget  -= level;
      }
      if (fr->left) qu.push(fr->left);
      if (fr->right) qu.push(fr->right);
    }

  }

  return count;
}