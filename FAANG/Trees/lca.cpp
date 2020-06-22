
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

print(root->left );
cout<<root->data<<" ";
print(root->right ) ;



}

Node* LCA ( Node* root , int n1 ,int n2 ) { 

if(root == NULL  ) return NULL ; 

trace( root -> data ) ;

if(root->data == n1 || root->data == n2  ) return root ;


if((root->data > n1 && root->data < n2 )  || ( root->data > n2 && root->data < n1 )) return root ; 


if(root->data > n1 && root->data > n2 ) 
	return  LCA(root->left , n1 , n2 ) ;

else 
	 return LCA(root->right , n1 , n2 ) ; 

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Node *root=CreateTree();
   	
   	int node1 , node2 ;
   	cin>>node1>>node2;
   	trace(node1,node2);
   	print( root ) ;

   	cout<<endl;
   	Node* ans  = LCA ( root , node1 , node2 );

   	if(root != NULL )
   	trace(ans->data ); 
   	else trace("Not found " );
    return 0;
}
