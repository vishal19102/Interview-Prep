
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


vector<int> moveZeroes(vector<int>& arr) {
	// write your awesome code here
	int i = 0 ;
	int j = 1;

	while ( j < arr.size() ) {
		if (arr[i] == 0 and arr[j] != 0 ) {
			trace(i , j , arr[i] , arr[j]);
			arr[i] = arr[j];
			arr[j] = 0;
			i++;
			j++;
		}
		else if ( arr[i] == 0 and arr[j] == 0 ) {
			j++;
		}
		else {
			i++;
			if (i == j )
				j++;
		}

	}

	for (auto i : arr ) cout << i << " ";
	cout << endl;
	return arr;
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
		int n ;
		cin >> n;
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		moveZeroes(nums);
	}
	return 0;
}
