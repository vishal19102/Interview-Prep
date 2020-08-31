
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




int minCoins(vector<int>  &coins , int V , vector<int> &dp ) {

	if (V == 0 ) return 0 ;

	if (V < 0 ) return INT_MAX ;

	if (dp[V] != -1 ) return dp[V];

	int ans = INT_MAX ;

	trace(V);
	for (int i = 0 ; i < coins.size() ; i++ ) {
		if (coins[i] <= V ) {
			int currRes =  minCoins(coins , V - coins[i] , dp );
			if (currRes != -3 )
				ans = min(ans , currRes  + 1 ) ;
		}
	}
	if (ans == INT_MAX ) ans = -3  ;
	return dp[V] = ans ;
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
		int V , N ;
		cin >> V >> N ;
		vector<int> coins ( N ) ;
		for (int i = 0 ; i < N ; i++ )
			cin >> coins[i];

		vector<int> dp(V + 1 , -1 ) ;
		cout << minCoins ( coins , V , dp ) << endl;
	}
	return 0;
}
