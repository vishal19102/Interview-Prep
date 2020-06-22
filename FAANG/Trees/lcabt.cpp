
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

Node* LCA ( Node* root , int d1 , int d2  ) { 


if(root == NULL ) return root ;

if(root->data == d1 || root->data == d2 ) return root ; 


Node* lcaleft = LCA ( root->left , d1 , d2 ) ;
Node* lcaright = LCA (root->right , d1 ,d2 ) ;

// if(!lcaleft and !lcaright ) return NULL ;

if(lcaleft && lcaright ) return root ; 


if(lcaleft ) return lcaleft ;

else  return lcaright ;


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
   	//trace(node1,node2);
   	Node* ans  = LCA ( root , node1 , node2 );

   	if(root != NULL )
   	cout<<(ans->data )<<endl; 
   	else trace("Not found " );
    return 0;
}
