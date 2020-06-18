
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

		temp->left = new node(no);

		q.push(temp->left);

		if(i>=nums.size()) break;

		no = nums[i++];

		temp->right = new node(no);

		if(i>=nums.size()) break;
	
		q.push(temp->left);

		}

	return root;
}



void levelorder(node* root ) { 

queue<node*> qu;

qu.push(root);

while(!qu.empty()){
	node* fr = qu.front();qu.pop();

	cout<<fr->data<<" ";

	if(fr->left)
		qu.push(fr->left);

	if(fr->right)
		qu.push(fr->right);
}

}


int summ(node* root ) { 

	if(root==NULL)
		return 0 ;

	int leftsum = summ(root->left);
	int righttsum = summ(root->right);

	return leftsum + righttsum + root->data;
}

int countSubtrees(node* root ,int sm) { 

	int count = 0 ;

	if(root==NULL)
		return  0 ;

	if(summ(root)==sm)
		count += 1 ;

	int leftcount = countSubtrees(root->left,sm);
	int rightcount = countSubtrees(root->right ,sm);

	count += leftcount + rightcount ;



	return count ; 
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    cin>>t;
    while(t--){
      cin.ignore();
      cin.getline(a,1000);
      StringtoInt();
      int sm ;
      cin>>sm;
      node* root = createTree();
      levelorder(root);cout<<endl;
      trace(sm);
      cout<<countSubtrees(root,sm)<<endl;
    }
    return 0;
}
