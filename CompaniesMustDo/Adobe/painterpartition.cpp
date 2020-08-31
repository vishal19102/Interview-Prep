
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
#include <numeric>
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


bool checkPossible(int time , int k  , vector<int>  &nums ) {

	int curP = 1 ;
	int curTime = 0 ;
	for (int i  = 0 ; i  < nums.size() ; i++ )  {
		curTime += nums[i];
		if (curTime > time ) {
			curP++;
			curTime = nums[i];
		}
	}
	if (curP <= k ) return true ;
	else return false ;
}



int binarySearch(vector<int>  &nums , int st , int en , int k ) {


	int mid =  0 ;
	int ans = 0 ;
	while (st <= en ) {
		mid  = st + ( en - st ) / 2 ;
		bool check = checkPossible(mid , k , nums ) ;
		if (check) {
			ans = mid ;
			en = mid - 1 ;
		}
		else {
			st = mid + 1 ;
		}
	}

	return ans;
}




void minimumTime(vector<int> &boards , int k ) {

	int mini = *max_element	(boards.begin(), boards.end()) ;
	int totTime = accumulate(boards.begin(), boards.end()  , 0 ) ;

	// min Time ..	.
	int minTime = binarySearch(boards , mini , totTime , k ) ;

	cout << (minTime) << endl;
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
		int k ;
		cin >> k;
		int n ;
		cin >> n;
		vector<int> nums ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> nums[i];
		minimumTime(nums , k ) ;
	}
	return 0;
}
