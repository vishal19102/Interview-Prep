
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


int maximumProduct(vector<int>& arr) {
	// write your awesome code here
	int minA = INT_MAX, minB = INT_MAX , maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;

	for (int i = 0 ; i < arr.size() ; i++ ) {
		if (arr[i] > maxA)
		{
			maxC = maxB;
			maxB = maxA;
			maxA = arr[i];
		}
		else if (arr[i] > maxB)
		{
			maxC = maxB;
			maxB = arr[i];
		}

		else if (arr[i] > maxC)
			maxC = arr[i];

		if (arr[i] < minA)
		{
			minB = minA;
			minA = arr[i];
		}
		else if (arr[i] < minB)
			minB = arr[i];
	}

	int p1 = minA * minB * maxA ;
	int p2 = maxA * maxB * maxC ;

	return max(p1, p2);
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
		trace(maxSubArrayProduct(nums));

	}
	return 0;
}
