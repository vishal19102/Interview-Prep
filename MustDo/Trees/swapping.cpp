// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if(!n) return true;
    if( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int,int>> &mismatch )
{
    if( !a && !b ) return true;
    if( !a || !b ) return false;
    
    if( a->data != b->data )
        mismatch.push_back( pair<int,int> (a->data,b->data) );
    
    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}

struct Node *correctBST( struct Node* root );

int main()
{
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif

    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);
        
        root = correctBST(root);
        
        // check 1: is tree now a BST
        if( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout<< "0\n";
            continue;
        }
        
        // check 2: comparing with duplicate tree
        
        vector<pair<int,int>> mismatch;
        // a vector to store data of mismatching nodes
        
        if( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout<< "0\n";
            continue;
        }
        
        // finally, analysing the mismatching nodes
        if( mismatch.size() !=2 || mismatch[0].first!=mismatch[1].second || mismatch[0].second!=mismatch[1].first )
            cout<<"0\n";
        else cout<<"1\n";
    }
	return 0;
}

struct Node* a , *b;
void validateTree(struct Node* root , int st , int en  ){

    if(root == NULL ) return ; 

    if(root->data >= st and root->data <= en ){
        validateTree(root->left, st ,root->data );
        validateTree(root->right, root->data ,en);
    }
    else{
        if(a == NULL ){
            a = root ;
        }
        else {
            b =root ;
        }
    }
    return ; 
}

struct Node *correctBST( struct Node* root )
{
    // add code here.
    //trace(root->data);
    validateTree(root , -10000000 , 10000000 );
    trace(a->data);
    trace(b->data);
    int d = a->data;
    a->data = b->data;
    b->data = d ;
    a = NULL;
    b = NULL;
    return root  ;    
}   

