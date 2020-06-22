
// Created By Vishal Srivastava .... 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

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

#define output(x) cout<<x<<"\n";
#define long long int int 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string,int> pp;

struct Node
{	
	int data;
	Node* left , *right ;
	Node(int d ){
		data = d;
		left = right = NULL ;
	}	
};


Node* CreateTree() {
	int d;
	cin>>d;
	Node *root=new Node(d);
	string str;
	cin>>str;
	if(str=="true")
	root->left=CreateTree();
	cin>>str;
	if(str=="true")
	root->right=CreateTree();
	return root;
}

void print(Node* root ) {
	if(root == NULL ) return ;

	// work for root.....
	if(root->left ) cout<<root->left->data<<" <- " ;
	else cout<<" <- " ;
	cout<<root->data<<" -> ";
	if(root->right ) cout<<root->right->data<<"" ;
	else cout<<"" ;
	cout<<endl;
	print(root->left);
	print(root->right);
}

void addrow(Node* root , int depth , int value ,int curdepth) {

	if(root == NULL ) return  ; 

	if(curdepth == depth-1 ){
		Node* leftptr = root->left;
		Node* rightptr = root->right;

		Node* newnode = new Node(value);
		Node* newnode1 = new Node(value);

		newnode->left = leftptr;
		newnode1->right = rightptr;

		root->left = newnode;
		root->right = newnode1;


		return ;
	}
	else{
		addrow(root->left , depth , value , curdepth + 1 ) ;
		addrow(root->right , depth , value , curdepth + 1 ) ;

	}
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Node* root = CreateTree();
    int val , depth ;
    cin>>val>>depth;

    addrow(root,depth ,val , 1 ) ;

    print(root);

    return 0;
}
