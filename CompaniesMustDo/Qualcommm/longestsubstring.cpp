
#include <bits/stdc++.h>

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
string longestPalindrome(string);

int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cout << longestPalindrome(str) << endl;
	}
	return 0;
}

int longestSubstring(string str , int i , int j, int** dp ) {

	if ( i == j ) return dp[i][j] =  1;

	if ( i > j ) return dp[i][j]  = 0 ;

	int ans = 0 ;
	if (str[i] == str[j]) {
		//trace(i, j, str[i], str[j]);
		ans = 2 + longestSubstring(str , i + 1, j - 1, dp );
	}
	else return dp[i][j] = INT_MIN;
	dp[i][j] = ans;

	return dp[i][j];
}



string longestPalindrome(string A) {
	// code here
	int n = A.length();
	int**dp = new int*[n] ;
	int m = n;
	for (int i  = 0 ; i < n ; i++ ) {
		dp[i] = new int[m];
		for (int j = 0; j < m ; j++ )
			dp[i][j] = -1;

	}
	int maxlength = 1 ,  maxi = 0  ,  maxj = 0	 ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0 ; j < n ; j ++ ) {
			int currlength = longestSubstring(A , i , j , dp);
			if (maxlength < currlength ) {
				maxlength = currlength;
				maxi = i;
				maxj = j;

			}
		}
	}
	string res = A.substr( maxi , maxj - maxi + 1 );
	return res ;
}