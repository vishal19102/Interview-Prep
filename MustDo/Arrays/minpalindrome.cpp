
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

int bottomUpLCS(string str, string revstr ) {

	int n = str.length();
	int**dp = new int*[n + 1 ] ;
	int m = n;
	for (int i  = 0 ; i <= n ; i++ ) {
		dp[i] = new int[m + 1 ];
		for (int j = 0; j <= m ; j++ )
			dp[i][j] = -1;

	}
	for (int i = 0; i <= n ; i++ ) {
		for (int j =  0; j <= n ; j++ ) {
			if (i == 0 or j == 0 ) dp[i][j] = 0 ;
			else if (str[i - 1] == revstr[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1 ][j]);
			}
		}
	}
	return dp[n][n];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int n = str.length();
		int**dp = new int*[n] ;
		int m = n;
		for (int i  = 0 ; i < n ; i++ ) {
			dp[i] = new int[m];
			for (int j = 0; j < m ; j++ )
				dp[i][j] = -1;

		}
		string revstr = str;
		reverse(revstr.begin(), revstr.end())  ;
		//cout << minInsertions(str , revstr , n - 1 , n - 1 , dp ) << endl;
		cout << n -  bottomUpLCS(str, revstr) << endl;
	}
	return 0;
}
