
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


vector<vector<int>> sum4(vector<int> &nums , int sm )  {

	vector<vector<int>> ans ;
	int N = nums.size();
	sort(nums.begin(), nums.end());
	unordered_map<int, vector<pair<int, int>> > idx;

	for (int i = 1 ; i < N - 1; i++ ) {
		for (int j = i + 1 ; j < N ; j++  ) {
			int cr_sum = nums[i] + nums[j];
			int diff_sum = sm - cr_sum ;
			if (idx.find(diff_sum) != idx.end()) {
				for (auto [fr, se] : idx[diff_sum]) {
					vector<int>  temp = {fr , se , nums[i] , nums[j] } ;
					ans.push_back(temp);
				}
			}
		}
		for (int k = 0 ; k < i  ; k++ ) {
			int cr_sum = nums[k] + nums[i];
			idx[cr_sum].push_back({nums[k] , nums[i]});
		}
	}
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
		int sm ; cin >> sm;
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		vector<vector<int>> ans = sum4(nums, sm );
		for (auto lst : ans ) {
			cout << lst[0] << " " << lst[1] << " " << lst[2] << " " << lst[3] << " $ ";
		}
		cout << endl;
	}
	return 0;
}
