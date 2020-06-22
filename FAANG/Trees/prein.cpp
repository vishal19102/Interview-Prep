
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
	node* left , * right ;

	node(int d ) {

		data = d ;
		left = right = NULL ;	
	}
};

int id ; 

node* buildTree(vector<int> &preorder , vector<int> &inorder , int se ,int en) {

	if(se > en ) return NULL ; 

	int dt = preorder[id++] ;

	node* root = new node(dt);
	

	int idx = 0;
	for(int i = se ; i <= en ; i++ ) {
		if(dt==inorder[i]) {
			idx = i ; 
			break;
		}
	}
    root->left = buildTree(preorder,inorder , se , idx-1  ); 
	root->right = buildTree(preorder,inorder , idx+1 , en );
	
	return root ; 
}

void print(node* root ){

    if(root == NULL ) return ; 

 
   
    // current node ...

    if( root->left ) cout<<root->left->data<<" => " ; else cout<<"END => " ;

    cout<<root->data<<" " ;

    if( root->right ) cout<<" <= "<< root->right->data ; else cout<<" <= END" ;

    cout<<endl;

    print( root->left ) ;

    print( root->right );

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n , m ;
    cin>>n ; 
    vector<int> preorder ( n ) ;

    for(int i = 0 ; i < n ; i++ ) 
    	cin>>preorder[i] ;

    cin>> m ;
    vector<int>  inorder ( m ) ;

    for(int i = 0 ; i < m ; i++ )
    	cin>>inorder[i];

    node* root = NULL ;
    id = 0 ;
    root = buildTree( preorder , inorder , 0  , n-1   );

    print(root );
    return 0;
}
