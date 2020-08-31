// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Functiuon to return number of trees

// Return the total number of BSTs possible with keys [1....N] inclusive.

int numTrees(int n ) {

	int dp[n + 1];
	fill_n(dp , (n + 1) , 0 ) ;

	dp[0] = 1 ;
	dp[1] = 1 ;
	for (int i = 2 ; i <= n ; i++ ) {
		for (int j = 1 ; j <= i ; j++ ) {
			dp[i]  = (dp[i] % 1000000007 + (dp[i - j ] * dp[j - 1 ] ) % 1000000007)  % 1000000007 ;
		}
	}
	return dp[n] % 1000000007 ;
}

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << numTrees(n) << "\n";
	}
}	  // } Driver Code Ends