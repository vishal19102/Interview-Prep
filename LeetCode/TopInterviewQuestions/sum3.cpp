
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


void StringToInt(vector<int> &nums , string str1 ) {

	str1 = str1.substr(1, str1.size() - 2);
	char* str = new char(str1.length() + 1 );
	strcpy(str , str1.c_str() );
	char* token = strtok(str , ",");
	while (token != NULL ) {
		nums.push_back(stoi(token));
		//trace(token);
		token = strtok(NULL , ",");
	}
}


vector<vector<int>> threeSum(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	set<vector<int>> res ;
	for (int i = 0 ; i < nums.size()  ; i++ ) {
		vector<int> temp ;
		int val = nums[i];
		int left  = i + 1 ;
		int right = nums.size() - 1 ;
		while (left < right ) {
			int cursum = val + nums[left] + nums[right];
			if (cursum == 0 ) {
				temp.push_back(val);
				temp.push_back(nums[left]);
				temp.push_back(nums[right]);
				res.insert(temp);
				//trace(val , nums[left] , nums[right]);
				break;
			}
			else if ( cursum > 0 ) {
				right--;
			}
			else {
				left++;
			}
		}
	}
	vector<vector<int> >  finalRes ;
	for (auto i : res ) {
		trace(i[0] , i[1] , i[2]);
		finalRes.push_back(i);
	}
	return finalRes ;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	string str ;
	cin >> str;
	vector<int> nums ;
	StringToInt(nums , str );
	threeSum(nums);
	return 0;
}
