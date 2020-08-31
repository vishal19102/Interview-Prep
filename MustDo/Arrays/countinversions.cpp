
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


int countInversion(vector<int> &nums , int st , int mid , int en ) {

	int inversions = 0 ;
	vector<int> tmp ( en - st + 1 );

	int i  = st ;
	int j =  mid + 1  ;
	int k = 0 ;

	while ( i  <= mid and j <= en ) {

		if ( nums[i] <= nums[j] ) {
			tmp[k] = nums[i];
			i++ ;
			k++ ;
		}
		else {
			inversions += mid + 1 - i ;
			tmp[k] = nums[j];
			j++;
			k++;
		}

	}

	while ( i <= mid ) {
		tmp[k] = nums[i];
		k++;
		i++;
	}
	while ( j  <= en ) {
		tmp[k] = nums[j];
		k++;
		j++;
	}

	for (int i = st ;  i <= en ; i ++ ) {
		nums[i] = tmp[i - st ];
	}

	return inversions ;
}


int countInversionsSort(vector<int>  &nums , int st , int en ) {


	if (st < en ) {
		int mid = (st + en) / 2 ;
		int lft = countInversionsSort(nums , st, mid ) ;
		int rgt = countInversionsSort(nums, mid + 1, en ) ;
		int tot = countInversion(nums , st , mid  , en ) ;

		return lft + rgt + tot ;

	}

	return 0 ;
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
		int ans = countInversionsSort(nums , 0 , n - 1 ) ;
		cout << ans << endl;
	}
	return 0;
}
