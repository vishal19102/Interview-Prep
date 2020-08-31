
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


int goldCoins(vector<int> &nums , int** dp  , int i , int j ) {

	if ( i > j ) return 0 ;


	if (dp[i][j] != -1 ) return dp[i][j];


	int op1 = nums[i];

	int op2 = nums[j];

	op1  += min( goldCoins(nums , dp , i + 2 , j) , goldCoins(nums , dp , i + 1 , j - 1 )) ;
	op2  += min( goldCoins(nums , dp , i , j - 2 ) , goldCoins(nums , dp , i + 1 , j - 1 )) ;

	return dp[i][j] = max( op1 , op2 ) ;

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		int**dp = new int*[n] ;
		int m = n;
		for (int i  = 0 ; i < n ; i++ ) {
			dp[i] = new int[m];
			for (int j = 0; j < m ; j++ )
				dp[i][j] = -1;

		}
		cout << goldCoins(nums , dp , 0 , n - 1 ) << endl;
	}
	return 0;
}
