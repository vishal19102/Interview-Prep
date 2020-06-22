
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


struct node
{	
	int data;
	node* left, *right;
	node(int d){
		data = d;
		left=NULL;
		right=NULL;
	}
};

node* CreateTree(){
	int dt ;
	cin>>dt;
	node* root = new node(dt);

	queue<node*> qu;
	qu.push(root);

	while(!qu.empty()){
		cin>>dt;
		node* fr = qu.front(); qu.pop();
		if(dt != -1 ){
			node* newnode = new node(dt);
			fr->left = newnode;
			qu.push(newnode);
		}
		else{
			fr->left = NULL;
		}
		cin>>dt;
		if(dt != -1 ){
			node* newnode = new node(dt);
			fr->right = newnode;
			qu.push(newnode);
		}
		else{
			fr->right = NULL;
		}
	}
	return root;
}

int minTree(node* root ) {

if(root == NULL ) return -1 ;

if(root->left == NULL && root->right ==NULL ) return  root->data  ;

if( root->left ) return minTree(root->left);

return root->data;

}

int inorderSuccessor(node* root ,int val ,node* parent ,node* grandparent ) { 

	if(root == NULL ) return -1 ; 

	if(root->data == val ){
		if( root->right != NULL  ) return minTree(root->right);
		else if ( root->right == NULL && parent->right == root ) return grandparent->data;
		else if ( root->right == NULL && parent->left == root ) return parent->data;

	}
	else{
		if(root->data > val ) return inorderSuccessor(root->left ,val , root , parent );
		else return inorderSuccessor(root->right , val  , root , parent);
	}
	return -1 ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    node* root = CreateTree();
    int val ;
    cin>>val;
    inorderSuccessor(root , val , NULL , NULL ) ;
    return 0;
}
