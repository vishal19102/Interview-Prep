
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

#define printBreak() cout << "----------------------" << endl;
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;



int minCost(int i , int j , vector<vector<int> >  &matrix , vector<vector<int> > &memo ) {

	if ( i == 0 and j == 0 ) {
		//trace( matrix[i][j] , i , j );
		return memo[i][j] = matrix[i][j];
	}

	if ( i < 0 or j < 0 ) return INT_MAX;

	int op1 = minCost(i - 1, j , matrix , memo );

	int op2 = minCost(i , j - 1 , matrix , memo);

	int ans = min(op1 , op2 ) ;
	ans += matrix[i][j];

	//trace(ans , i , j );

	return memo[i][j] = ans ;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		int m ;
		cin >> m;
		vector<vector<int> > matrix(n , vector<int> (m , 0 ));
		for (int i = 0 ; i < n ; i++ )
			for (int j = 0 ; j < m ; j++ )
				cin >> matrix[i][j];

		for (auto i : matrix ) {
			for (auto j : i )
				cout << j << " ";
			cout << endl;
		}
		vector <vector<int>> memo(n , vector<int> ( n , INT_MAX )) ;
		trace(minCost( n - 1 , n - 1 , matrix , memo ) ) ;
	}
	return 0;
}
