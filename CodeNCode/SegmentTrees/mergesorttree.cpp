
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



class MergeSortTree
{
public:
	vector<vector<int> > tree ;
	MergeSortTree( int  n ) {
		tree = vector<vector<int> > (4 * n ) ;
	}

	void mergeTrees(int firstA, int secondA, int treeNode ) {

		vector<int> temp1 = tree[firstA];
		vector<int> temp2 = tree[secondA];

		vector<int> res ;

		int i = 0 ;
		int j = 0 ;
		while (i < temp1.size() and j < temp2.size()) {
			if (temp1[i] <= temp2[j]) {
				res.push_back(temp1[i]);
				i++;
			}
			else {
				res.push_back(temp2[j]);
				j++;
			}
		}

		while ( i < temp1.size()) {
			res.push_back(temp1[i++]);
		}
		while ( j < temp2.size()) {
			res.push_back(temp2[j++]);
		}

		tree[treeNode] = res ;
		return ;
	}

	void buildTree(vector<int>  &arr, int st , int en , int  treeNode) {

		if (st == en ) {
			tree[treeNode].push_back(arr[st]);
			return ;
		}
		int mid = st + (en - st ) / 2;
		buildTree(arr , st , mid , treeNode * 2 );
		buildTree(arr , mid + 1 , en , 2 * treeNode + 1 );

		mergeTrees( 2 * treeNode , 2 * treeNode + 1 , treeNode );
	}

	int queryTree(int st , int en , int qst , int qen , int k , int treeNode) {

		if (qen < st or qst > en ) return 0 ;

		if ( qst <= st and en <= qen ) {

			int ans = tree[treeNode].end() - upper_bound(tree[treeNode].begin(), tree[treeNode].end() , k );

			return ans ;
		}
		int mid = st + (en - st ) / 2 ;

		int op1 = queryTree(st , mid , qst , qen , k , 2 * treeNode);
		int op2 = queryTree(mid + 1 , en , qst , qen, k , 2 * treeNode + 1 );

		return op1 + op2 ;
	}


	void printTree() {
		for (auto lst : tree) {
			cout << "--------------------" << endl;
			for (auto elem : lst )
				cout << elem << " ";
			cout << endl;

		}
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
	MergeSortTree st (n) ;
	st.buildTree(nums , 0 , n - 1 , 1 );
	int m ;
	cin >> m;
	while (m--) {
		int a , b , c ;
		cin >> a >> b >> c;
		cout << (st.queryTree(0 , n - 1 , a - 1 , b - 1 , c , 1 )) << endl ;

	}

	return 0;
}
