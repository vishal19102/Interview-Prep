
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


int maxSquare(vector<vector<int>>  &matrix , int** dp , int i , int j ) {

	int n = matrix.size();
	int m  = matrix[0].size();

	if (i >= n or j >= m ) return 0 ;

	if (dp[i][j] != -1 ) return dp[i][j];
	int op1 = maxSquare(matrix , dp , i + 1 , j  );
	int op2 = maxSquare(matrix , dp , i + 1 , j + 1 );
	int op3 = maxSquare(matrix , dp , i , j + 1  );

	int ans = min ( op1 , min(op2, op3 )) ;

	if (matrix[i][j] == 1 ) ans++;
	else ans = 0 ;

	return dp[i][j] = ans ;
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int row , col ;
		cin >> row >> col;
		vector<vector<int> > matrix ( row , vector<int> (col , -1 )) ;
		for (int i = 0 ; i < row ; i++ ) {
			for (int j = 0 ; j < col ; j++ ) {
				cin >> matrix[i][j];
			}
		}
		int**dp = new int*[row] ;
		int m = col;
		for (int i  = 0 ; i < row ; i++ ) {
			dp[i] = new int[m];
			for (int j = 0; j < m ; j++ )
				dp[i][j] = -1;

		}
		int maxAns = 0;
		maxSquare(matrix, dp, 0, 0 );
		for (int i = 0 ; i < row ; i++ ) {
			for (int j = 0 ; j < col ; j++ ) {
				maxAns = max(maxAns , dp[i][j]);
			}
		}
		cout << maxAns << endl;
	}

	return 0;
}
