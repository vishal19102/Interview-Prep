
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


double findMedian(vector<int> &array, int startIndex, int endIndex)
{
	int indexDiff = (endIndex - startIndex);
	if (indexDiff % 2 == 0) // we are looking at odd number of elements
	{
		return array[startIndex + (indexDiff / 2)];
	}
	else
	{
		return 1.0 * (array[startIndex + (indexDiff / 2)] + array[startIndex + (indexDiff / 2) + 1]) / 2;
	}
}

double medians(vector<int>  &nums1 , vector<int> &nums2 , int st1 , int en1 , int st2, int en2 ) {

	if ((en1 - st1 == 0) && ((en2 - st2 == 0)))
		return (nums1[0] + nums2[0]) / 2;

	if ((en1 - st1 == 1 ) && (en2 - st2 == 1) ) {
		return (1.0) * (max(nums1[st1] , nums2[st2]) +  min(nums1[en1] , nums2[en2]) ) / 2 ;
	}

	double midV1 = findMedian(nums1 , st1 , en1 ) ;
	double midV2 = findMedian(nums2 , st2 , en2 ) ;

	int mid1 = st1 + ( en1 - st1 ) / 2 ;
	int mid2 = st2 + ( en2 - st2 ) / 2 ;
	if (midV1 == midV2) {
		return midV1 ;
	}

	if (midV1 < midV2 ) {
		st1 = mid1 ;
		if ((en1 - st1) % 2  == 0 )
			en2 = mid2 ;
		else
			en2 = mid2 + 1;
	}
	else {
		st2 = mid2 ;
		if ((en2 - st2) % 2 == 0 )
			en1 = mid1;
		else
			en1 = mid1 + 1  ;
	}

	return medians(nums1 , nums2  , st1 , en1 , st2 , en2 ) ;
}



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	if (nums1.size() == 0 ) {
		return findMedian(nums2 , 0 , nums2.size() - 1 ) ;
	}
	if (nums2.size() == 0 ) {
		return findMedian(nums1 , 0 , nums1.size() - 1 ) ;
	}

	return medians(nums1 , nums2, 0 , nums1.size() - 1 , 0 , nums2.size() - 1 );
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	string str , str1 ;
	cin >> str >> str1;
	vector<int> nums ;
	StringToInt(nums , str );
	vector<int> nums1 ;
	StringToInt(nums1 , str1 );
	cout << findMedianSortedArrays(nums , nums1 ) << endl ;

	return 0;
}
