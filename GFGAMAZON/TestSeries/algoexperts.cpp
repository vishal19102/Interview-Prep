
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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;

long long int project(vector<long long int>  algoExperts, vector<long long int>  Developers, int n)
{
	long long int dpf[n + 5] = {0}, dpb[n + 5] = {0};
	long long int a[n + 5] = {0}, b[n + 5] = {0};
	long long int ans = 0;

	// Making the array 1 indexed.
	for (int i = 0; i < n; i++)
		a[i + 1] = algoExperts[i];
	for (int i = 0; i < n - 1; i++)
		b[i + 1] = Developers[i];

	// Calculating the product sum from front
	for (int i = 1; i <= n; i++) {
		dpf[i] = dpf[i - 1] + a[i] * b[i];
		trace(dpf[i] , i );
	}
	cout << "---------------------------" << endl;
	// Calculating the product sum from back
	for (int i = n; i > 0; i--) {
		dpb[i] = dpb[i + 1] + a[i] * b[i - 1];
		trace(dpb[i] , i );
	}

	// placing zero at (i+1)th index and storing the maximum answer
	for (int i = 0; i < n; i++)
		ans = max(dpf[i] + dpb[i + 2], ans);

	return ans;
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
		vector<long long int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		vector<long long int> nums2 (n - 1 );
		for (int i = 0 ; i < n - 1 ; i++ ) cin >> nums2[i];
		trace(project(nums, nums2, n));
	}
	return 0;
}
