
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


int minCost(vector<int>  &dimensions , int i , int j , vector<vector<int>> &memo ) {

	if (i >= j ) return 0 ;

	if (memo[i][j] != -1) return memo[i][j];

	int ans = INT_MAX;
	for (int k = i ; k <= j - 1 ;  k++ ) {
		int temp = minCost(dimensions, i, k , memo);
		temp += minCost(dimensions , k + 1, j , memo);

		temp += dimensions[i - 1 ] * dimensions[k] * dimensions[j];

		ans = min(ans , temp);
	}

	return memo[i][j] =  ans ;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		vector<int> dimensions ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> dimensions[i];
		vector<vector<int>> memo ( n + 1 , vector<int> (n + 1, -1 ));
		int ans = minCost(dimensions , 1 , n - 1 , memo);
		cout << ans << endl;
	}
	return 0;
}
