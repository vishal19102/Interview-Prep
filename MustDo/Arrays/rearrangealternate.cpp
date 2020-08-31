
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


void rearrange(vector<int>  &nums ) {

	int maxelem  = *max_element(nums.begin(), nums.end())  + 1 ;

	int mini = 0 ;
	int maxi = nums.size() - 1;
	for (int i =  0 ; i < nums.size() ; i++ ) {
		if ( i % 2 == 0 ) {
			nums[i] = nums[i] + (nums[maxi--] % maxelem) * maxelem ;
		}
		else {
			nums[i] = nums[i] + (nums[mini++] % maxelem) * maxelem ;
		}
	}
	for (int i = 0 ; i < nums.size() ; i++ )
		cout << nums[i] / maxelem << " ";
	cout << endl;
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
		rearrange(nums);
	}
	return 0;
}
