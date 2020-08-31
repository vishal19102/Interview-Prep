
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


// bool cmp(pair<int, int>  &a , pair<int, int> &b) {

// 	return a.first < b.first ;
// }

void sortFreq(vector<int>  &nums ) {

	unordered_map<int, pair<int, int> > freqIndex ;

	for (int i = 0 ; i < nums.size() ; i++ ) {
		if (freqIndex.find(nums[i]) == freqIndex.end()) {
			freqIndex[nums[i]] = { i , 1 } ;
		}
		else {
			int idx = freqIndex[nums[i]].first;
			int val = freqIndex[nums[i]].second  + 1 ;
			freqIndex[nums[i]] = {idx , val };
		}
	}

	vector<vector<pair<int, int>> > indexes ( nums.size()  + 1 ) ;

	for (auto it : freqIndex ) {
		indexes[it.second.second].push_back({it.first, it.second.first});
	}

	for (int i = nums.size() ; i >= 0  ; i--) {
		if (indexes[i].size() != 0 ) {
			sort(indexes[i].begin(), indexes[i].end() );
			for (int j = 0 ; j < indexes[i].size() ; j++ ) {
				int k = i ;
				while (k--)
					cout << indexes[i][j].first << " ";
			}
		}
	}

	cout << endl;
	return ;
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
		sortFreq(nums);
	}
	return 0;
}
