
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

node* buildTree(vector<int> &postorder , vector<int> &inorder , int se ,int en) {

	if(se > en ) return NULL ; 

	int dt = postorder[id--] ;

	node* root = new node(dt);
	

	int idx = 0;
	for(int i = se ; i <= en ; i++ ) {
		if(dt==inorder[i]) {
			idx = i ; 
			break;
		}
	}

	root->right = buildTree(postorder,inorder , idx+1 , en );
	root->left = buildTree(postorder,inorder , se , idx-1  ); 
	
	return root ; 
}

void print(node* root ){

	if(root == NULL ) return ; 

	cout<<root->data<<" ";
	print(root->left );
	print(root->right );

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ;
    cin>>n;
    vector<int> postorder ( n ) , inorder( n ) ;

    for(int i = 0 ; i < n ; i++ ) 
    	cin>>inorder[i] ;

    for(int i = 0 ; i < n ; i++ )
    	cin>>postorder[i];

    node* root = NULL ;
    id = n-1 ;
    root = buildTree( postorder , inorder , 0  , n-1   );

    print(root );
    return 0;
}
