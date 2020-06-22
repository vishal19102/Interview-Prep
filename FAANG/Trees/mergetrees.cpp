
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


char a[1000];

vector<int> nums;

void StringtoInt(){

    char* word = strtok(a , " ");
    while(word!=NULL){
        nums.push_back(stoi(word));
        word = strtok(NULL," " );
    } 
}

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

node* createTree(){

    if(nums.size()==0) return NULL;

    int dt = nums[0];

    node* root = new node(dt);

    int i = 1;

    queue<node*> q ;

    q.push(root);

    while(!q.empty() && i < nums.size()) { 

        node* temp = q.front() ; q.pop();

        int no = nums[i++];

        if(no != -1 ){
            temp->left = new node(no);
            q.push(temp->left);
        }
        else 
            temp->left = NULL;

        if(i>=nums.size()) break;

        no = nums[i++];

        if(no != -1 ){
            temp->right = new node(no);
            q.push(temp->right);
        }
        else {
            temp->right = NULL;
        }
        if(i>=nums.size()) break;
    
        }

    return root;
}

void print(node* root ) {
	if(root == NULL ) return ;

	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    
    node* tree1 = createTree();
    node* tree2 = createTree();

    print(tree1);
    print(tree2);
    return 0;
}
