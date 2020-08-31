
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



void pairs(vector<int> &nums , int sum ) {

	sort(nums.begin(), nums.end()) ;

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[nums[i]]++;


	int i = 0 ;
	int j = nums.size() - 1 ;

	int count = 0 ;
	while ( i < j ) {
		int s = nums[i] + nums[j];

		if (s == sum ) {
			count ++ ;
			if ( (i + 1 < nums.size()) and nums[i + 1] == nums[i] )
				i++;
			else if ( (j >= 1 ) and nums[j - 1] == nums[j])
				j--;
			else {
				i++;
				j--;
			}
		}
		else if ( s < sum ) i++;
		else j--;
	}
	trace(count );

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
		int n , sum ;
		cin >> n >> sum;
		vector<int> nums ( n ) ;
		for (int i = 0 ; i < n ; i++ )
			cin >> nums[i];
		pairs(nums , sum );
	}
	return 0;
}
