
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
	Node* left ,*right , *nextright ;
	Node(int d ) { 
		data = d; 
		left = right = nextright = NULL ;
	}
};

Node* CreateTree() {
	int dt ;
	cin>>dt;
	if(dt == -1 ) return NULL ;
	Node* root = new Node( dt ) ; 
	trace(dt);
	root->left = CreateTree();
	root->right = CreateTree();
	return root ; 

}

void  levelorder(Node* root ) { 

	queue<Node*> qu;

	qu.push(root);
	qu.push(NULL);
	while(!qu.empty()){
		Node* fr = qu.front();
		qu.pop();
		if( fr == NULL ) { 
			if(!qu.empty()) qu.push(NULL);
		}
		else {
			cout<<fr->data<<" " ;
			if(fr->left)
			qu.push(fr->left);

			if(fr->right)
				qu.push(fr->right);
			}
			fr->nextright = qu.front();
		}

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Node* tree = CreateTree() ;

     levelorder(tree);

    //for(auto i : res ) cout<<i<<" " ;

    cout<<endl;
    return 0;
}
