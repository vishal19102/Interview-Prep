
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


bool cmp(pair<int, int>  &a , pair<int, int>  &b ) {

	return a.first < b.first ;
}
void maxOverlap(vector<pair<int, int>> intervals  ) {

	vector < pair<par, bool>> times ;
	for (auto  i : intervals ) {
		times.push_back({i.first , false });
		times.push_back({i.second , true  });
	}
	sort(times.begin() , times.end()) ;

	int curMax = 0 ;
	int maxCur = 0 ;
	int time =  0;
	for (auto i : times  ) {
		if (i.second)   {
			maxCur = max(maxCur , curMax);
			if (maxCur == curMax)
				time = i.first;
			curMax --  ;
			if (curMax < 0 ) curMax = 0  ;
		}
		else curMax++;
	}
	cout << maxCur << " " << time << endl;
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
		cin >> n ;
		vector<pair<int, int>> intervals ( n ) ;

		for (int i = 0 ; i < n ; i++ ) {
			cin >> intervals[i].first ;
		}
		for (int i = 0 ; i < n ; i++ ) {
			cin >> intervals[i].second ;
		}

		maxOverlap(intervals ) ;
	}
	return 0;
}
