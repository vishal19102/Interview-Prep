
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


vector<int>   levelOrder(node* root ) {

	if(root == NULL ) return { } ; 

	vector<int>  res ;
	queue<node*> qu ; 
	qu.push(root) ;
	qu.push(NULL);

	int currentmax = -1 ;
	while(!qu.empty()) { 

		node* fr = qu.front() ; qu.pop();
		
		if(fr == NULL ) {
			res.push_back(currentmax);
			currentmax = -1 ; 
			if(!qu.empty()) qu.push(NULL);	
		}
		else {
			if(fr->left) qu.push(fr->left);
			if(fr->right) qu.push(fr->right);
			if(fr->data > currentmax ) currentmax = fr->data;

		}

	}

	return res ; 
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
  	node* root = CreateTree();
  	vector<int>  res =  levelOrder(root);
  	for(auto i : res ) cout<<i<<" ";

    return 0;
}
