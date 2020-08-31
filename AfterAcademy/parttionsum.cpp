
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



int subsetSum(vector<int> &arr , int sum , int pos , int **dp ) {

	if (pos < 0 ) {
		if (sum == 0 ) return true ;
		else return false ;
	}
	if (sum == 0 ) return true ;

	if (dp[pos][sum] != -1  ) return dp[pos][sum];

	int op1 = 0 ;
	if (sum - arr[pos] >= 0 )
		op1 = subsetSum(arr , sum - arr[pos] , pos - 1 , dp );

	int op2 = subsetSum(arr , sum  , pos - 1 , dp );

	dp[pos][sum] = op1 | op2  ;

	return dp[pos][sum] ;
}



bool canPartition(vector<int>& arr) {
	// write your awesome code here
	int sum = 0 ;
	for (int i = 0 ; i < arr.size() ; i++ ) {
		sum += arr[i] ;
	}
	if (sum % 2 != 0 ) return false ;

	int**dp = new int*[arr.size()] ;
	int m = (sum / 2) + 1 ;
	for (int i  = 0 ; i < arr.size() ; i++ ) {
		dp[i] = new int[m];
		for (int j = 0; j < m ; j++ )
			dp[i][j] = -1 ;

	}
	int ans = subsetSum(arr , sum / 2 , arr.size() - 1  , dp ) ;
	return ans ;
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
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		canPartition(nums);
	}
	return 0;
}
