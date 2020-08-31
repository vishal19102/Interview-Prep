
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


vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
	// write your awesome code here
	priority_queue < pair < int, pair<int, int>> qu ;

	int a1 = v1[0];
	int b1 = v2[0];


}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int n1 , n2 ;
		cin >> n1 >> n2 ;
		vector<int> nums ( n1 );
		for (int i = 0 ; i < n1 ; i++ ) cin >> nums[i];
		vector<int> nums1 ( n2 );
		for (int i = 0 ; i < n2 ; i++ ) cin >> nums1[i];
		int k ;
		cin >> k;
		kSmallestPairs(nums1 , num2 , k );
	}
	return 0;
}
