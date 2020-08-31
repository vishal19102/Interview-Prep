// { Driver Code Starts
#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n;
        i = n;

        Node* root = NULL;
        queue <Node*> q;
        while (i > 0)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (!root) {
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if (c == 'L') {
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin >> a >> b >> c;
            if (c == 'R') {
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i -= 2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
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

void topView(struct Node *root)
{
    //Your code here
    map<int, vector<int> > res = verticalOrder(root);

    for (auto i : res ) {
        for (auto node : i.second) {
            cout << node << " ";
            break;
        }
    }

}


