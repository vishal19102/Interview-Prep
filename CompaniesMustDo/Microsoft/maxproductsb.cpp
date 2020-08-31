
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


int maxProduct(vector<int> &nums , int n ) {

	int pp = 1 , np = 1 , maxVal = INT_MIN;
	bool hasPos = false , hasZero = false;

	for (auto i : nums ) {

		if ( i > 0 ) {
			hasPos = true ;
			pp = pp * i ;
			if (np != 1 ) {
				np = np * i ;
			}
		}
		else if (i < 0 ) {
			int temp = pp ;
			pp = max(1 , np * i );
			np = temp * i ;
		}
		else {
			np = pp = 1;
			hasZero = true ;
		}
		maxVal = max(maxVal , pp );
	}


	if (maxVal == 1 ) {
		if (hasPos) return 1;
		if (hasZero) return 0 ;
	}

	return maxVal;
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
		cout << maxProduct(nums , n) << endl;
	}
	return 0;
}
