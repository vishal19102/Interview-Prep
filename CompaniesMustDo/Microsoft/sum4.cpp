
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
typedef pair<string, int> pp;


bool ifPresent(int fr , int se , int i, int j, set<set<int> > setS ) {

	set<int> nos ;
	nos.insert(fr);
	nos.insert(se);
	nos.insert(i);
	nos.insert(j);
	if (setS.find(nos) == setS.end())
		return false;

	return true;
}





void sum4(vector<int>  &nums , int  X ) {

	int n = nums.size();
	unordered_map<int, set<pair<int, int>> > elems ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = i + 1 ; j < n ; j++ ) {
			int sum = nums[i] + nums[j];
			elems[sum].insert({ i , j });
		}
	}

	set<set<int> > setS ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = i + 1 ; j < n ; j++ ) {
			int cur_sum = nums[i] + nums[j];
			int diff_sum = X - cur_sum;
			if (elems.find(diff_sum) != elems.end()) {
				set<pair<int, int>> ppairs = elems[diff_sum];
				for (auto [fr , se] : ppairs ) {
					if (!ifPresent(fr, se, i, j , setS)) {
						//trace(fr, se, i, j );
						setS.insert({fr, se, i, j});
						trace(setS.size());
					}
				}
			}
		}
	}
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
		int sm ;
		cin >> sm;
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		sum4(nums , sm);
	}
	return 0;
}
