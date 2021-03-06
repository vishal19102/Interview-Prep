
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
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << std::endl;
	//use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define output(x) cout<<x<<"\n";
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<int, int> pp;

char a[1000];

vector<int> nums;

void StringtoInt() {

	char* word = strtok(a , " ");
	while (word != NULL) {
		nums.push_back(stoi(word));
		word = strtok(NULL, " " );
	}
}

struct TreeNode
{
	int val;
	TreeNode* left, *right;
	TreeNode(int d) {
		val = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* createTree() {

	if (nums.size() == 0) return NULL;

	int dt = nums[0];

	TreeNode* root = new TreeNode(dt);

	int i = 1;

	queue<TreeNode*> q ;

	q.push(root);

	while (!q.empty() && i < nums.size()) {

		TreeNode* temp = q.front() ; q.pop();

		int no = nums[i++];

		if (no != -1 ) {
			temp->left = new TreeNode(no);
			q.push(temp->left);
		}
		else
			temp->left = NULL;

		if (i >= nums.size()) break;

		no = nums[i++];

		if (no != -1 ) {
			temp->right = new TreeNode(no);
			q.push(temp->right);
		}
		else {
			temp->right = NULL;
		}
		if (i >= nums.size()) break;

	}

	return root;
}
vector<int>   levelOrder(TreeNode* root ) {

	if (root == NULL ) return { } ;

	vector<int>  res ;
	queue<TreeNode*> qu ;
	qu.push(root) ;
	qu.push(NULL);

	while (!qu.empty()) {

		TreeNode* fr = qu.front() ; qu.pop();

		if (fr == NULL ) {
			cout << endl;
			if (!qu.empty()) qu.push(NULL);
		}
		else {
			if (fr->left) qu.push(fr->left);
			if (fr->right) qu.push(fr->right);
			cout << fr->val << " ";

		}

	}

	return res ;
}


int max_sum ;
int binaryTreemax(TreeNode* root ) {

	if (root == NULL  ) return 0 ;

	int leftAns = binaryTreemax(root->left);
	int rightAns = binaryTreemax(root->right);

	int cur_max = root->val;
	if (leftAns >= 0) cur_max += leftAns;

	if (rightAns >= 0 ) cur_max += rightAns;

	max_sum = max(max_sum , cur_max );

	return root->val + max(0 , (leftAns , rightAns));
}

int maxPathSum(TreeNode* root) {
	max_sum = INT_MIN;
	binaryTreemax(root);
	return max_sum ;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin.getline(a , 1000000);
	StringtoInt();
	TreeNode* root = createTree();
	//levelOrder(root);
	cout << (maxPathSum(root)) << endl;
	return 0;
}
