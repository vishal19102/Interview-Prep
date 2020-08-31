
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

vector<int> spiralOrder ;
void recursiveSpiral(vector<vector<int>>& arr , int row , int col , int n , int m  ) {

	if ( row >= n or col >= m ) return ;

	// first row ...
	for (int j = 0 ; j < m ; j++ ) {
		cout << arr[row][j] << " ";
		spiralOrder.push_back(arr[row][j]);
	}

	// last column....
	for (int i = 1 ; i < n ; i++ ) {
		cout << arr[i][col] << " ";
		spiralOrder.push_back(arr[i][col]);
	}

	if ((n - 1) != row ) {
		for (int p = n - 1; p >= j; p--)
			cout << arr[m - 1][p] << " ";
	}
}


vector<int> spiralMatrix(vector<vector<int>>& arr) {
	// write your awesome code here
	int n = arr.size();
	int m = arr[0].size();
	spiralOrder = vector<int>  ( n + m );
	recursiveSpiral(arr , 0 , 0 , n , m );

	return spiralOrder;
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int n , m ;
		cin >> n >> m;
		vector<vector<int> > matrix ( n ) ;
		for (int i = 0; i < n; ++i) {
			matrix[i] = vector<int> ( m );
			for (int j = 0 ;  j < m ; j++ )
				cin >> matrix[i][j];
		}

		spiralMatrix(matrix);
	}
	return 0;
}
