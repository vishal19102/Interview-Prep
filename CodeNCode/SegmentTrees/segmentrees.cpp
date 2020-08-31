
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
typedef pair<string, int> pp;



class SegmentTrees {
	vector<int> tree ;
public:
	SegmentTrees(int n ) {
		tree = vector<int> ( 4 * n , -1 );
	}
	void buildTree(vector<int> &arr , int st , int en , int treeNode) {

		if (st == en ) {
			tree[treeNode] = arr[st];
			return ;
		}
		int mid = st + (en - st) / 2 ;
		buildTree(arr, st , mid , treeNode * 2 ) ;
		buildTree(arr , mid + 1 , en , treeNode * 2 + 1 ) ;

		tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1 ] ;

		return ;
	}
	void updateTree(vector<int> &arr, int st, int en , int idx , int val , int treeNode) {

		if (st == en ) {
			arr[idx] = val;
			tree[treeNode] = arr[idx];
			return ;
		}
		int mid = st + (en - st) / 2;
		if (idx <= mid ) {
			updateTree(arr , st , mid , idx , val, 2 * treeNode);
		}
		else {
			updateTree(arr , mid + 1, en, idx , val, 2 * treeNode + 1);
		}

		tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];

		return ;
	}
	int queryTree(int st, int en , int qst , int qen , int treeNode ) {

		if (qst > en or qen < st ) return 0 ;

		if (qst <= st and en <= qen ) return tree[treeNode];

		int mid = st + (en - st ) / 2;
		int op1 = queryTree(st , mid , qst, qen , 2 * treeNode);
		int op2 = queryTree(mid + 1 , en, qst, qen , 2 * treeNode + 1);

		return op1 + op2 ;
	}
	void printTree() {
		for (auto i : tree) if ( i != -1 ) trace(i);
	}

};




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n ;
	cin >> n;
	vector<int> nums ( n );
	for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
	SegmentTrees Stree ( n );
	Stree.buildTree(nums , 0 , n - 1, 1 ) ;
	Stree.printTree();
	trace(Stree.queryTree(0 , n - 1, 1, 3 , 1 ));
	Stree.updateTree(nums , 0 , n - 1 , 1 , 10 , 1 );
	Stree.printTree();
	trace(Stree.queryTree(0 , n - 1, 1, 3 , 1 ));

	return 0;
}
