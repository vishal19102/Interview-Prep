
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


vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

	if (intervals.size() == 0 ) return {};

	int i = 0;
	int st = intervals[i][0];
	int en = intervals[i][1];
	i = i + 1;
	vector<vector<int> > res ;
	while ( i < intervals.size() ) {
		int nst = intervals[i][0];
		int nen = intervals[i][1];
		trace(st , en);
		if ( st <= nst  and nst <= en  ) {
			if ( nen > en ) en = nen;
		}
		else {
			res.push_back({st , en });
			st = nst;
			en = nen;
			trace(st , en);
		}
		i++;
	}
	trace(st , en );
	trace(res.size());
	return res ;
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
		vector<vector<int>>  nums( n );
		for (int i = 0; i < n ; i++ ) {
			nums[i] = vector<int> ( 2) ;
			for (int j = 0 ; j < 2 ; j++) {
				cin >> nums[i][j];
			}
		}
		mergeIntervals(nums);
	}
	return 0;
}
