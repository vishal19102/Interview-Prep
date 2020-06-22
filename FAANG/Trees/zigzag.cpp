
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


struct TreeNode
{	
	int val;
	TreeNode* left , *right ;
	TreeNode(int d ){
		val = d;
		left = right = NULL ;
	}	
};


TreeNode* CreateTree() {
	int d;
	cin>>d;
	TreeNode *root=new TreeNode(d);
	string str;
	cin>>str;
	if(str=="true")
	root->left=CreateTree();
	cin>>str;
	if(str=="true")
	root->right=CreateTree();
	return root;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int> > res ; 

        queue<TreeNode*> qu ;

        qu.push(root);
        qu.push(NULL);

        vector<int>  temp ; 
        int level = 0 ;
        while(!qu.empty()) {
        	TreeNode* fr = qu.front(); qu.pop();

        	if(fr == NULL){
        		if(level%2==0) {
        			res.push_back(temp);
        		}
        		else{
        			reverse(temp.begin(), temp.end());
        			res.push_back(temp);
        		}
        		temp.clear();
        		if(!qu.empty()) qu.push(NULL);
        		level++;
        	}
        	else{
        		if(fr->left ) qu.push(fr->left);
        		if(fr->right ) qu.push(fr->right);

        		//trace(fr->val);
        		temp.push_back(fr->val);
        	}

        }

        return res ;  
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    TreeNode* root = CreateTree();

    vector<vector<int> > res =   zigzagLevelOrder(root);
    
    for(auto i : res ) {
    	for(auto j : i )
    		cout<<j<<" ";
    }
    return 0;
}
