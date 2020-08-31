
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

int subsetsbottomUP(vector<int>  &nums , int sum ) {

	int n = nums.size();
	vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));

	for (int i = 1 ; i <= sum ; i++ )
		memo[0][i] = 0 ;

	for (int i = 0 ; i <= n ; i++ )
		memo[i][0] = 1;

	for (int i = 1; i <= n ; i++ ) {
		for (int j = 1 ; j <= sum ; j++ ) {

			if (nums[i - 1] > j )
				memo[i][j] = memo[i - 1][j];
			else {
				memo[i][j] = memo[i - 1][j] + memo[i - 1 ][j - nums[i - 1 ]];
			}
		}
	}
	return memo[n][sum] ;
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
		int sum ;
		cin >> sum;
		cout << subsetsbottomUP(nums , sum) << endl;
	}
	return 0;
}
