
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


void mergeArrays(vector<vector<int> >  arrays) {

	priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > qu ;
	int n = arrays[0].size();
	int k = arrays.size();
	vector<int> indexes ( k  , 1 );
	for (int i = 0 ; i < arrays.size() ; i++ ) {
		pair<int, int> pp = { arrays[i][0] , i };
		qu.push(pp);
	}
	while (!qu.empty()) {
		pair<int, int> pj ;
		pj = qu.top();
		qu.pop();
		int val = pj.first;
		int arrI = pj.second;
		int idx = indexes[arrI];
		if (idx < n ) {
			pair<int, int> p = {arrays[arrI][idx] , arrI };
			qu.push(p);
			indexes[arrI]++;
		}
		trace(val);
	}
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen(".. / input.txt", "r", stdin);
	freopen(".. / output.txt", "w", stdout);
#endif
	int k , n ;
	cin >> k >> n;
	vector<vector<int> >  arrays ( k ) ;
	for (int i = 0 ; i < k ; i++ ) {
		for (int j = 0 ; j < n ; j++ ) {
			int a ;
			cin >> a;
			arrays[i].push_back(a);
		}
	}
	mergeArrays(arrays);
	return 0;
}
