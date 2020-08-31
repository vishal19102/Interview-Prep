
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


int expandFromMiddle(string str, int left , int right ) {

	while ( str.length() > 0 and left >= 0 and right < str.length() and str[left] == str[right]) {
		left--;
		right++;
	}
	return right - left - 1;
}

string longestPalindrome(string A) {
	string str ( A );
	int maxlen = 0 ;
	int s = 0 ;
	int en = 0;
	for (int i = 0 ; i < str.length() ; i++ ) {
		int len1 = expandFromMiddle(str , i , i );
		int len2 = expandFromMiddle(str, i, i + 1);

		int len = max(len1, len2);

		if ( len > maxlen ) {
			maxlen = len;
			s = i - (maxlen - 1) / 2;
			en = i + (maxlen / 2) ;
		}
	}
	string res = (str.substr(s , en - s + 1));

	return res;
}


int lps(char* st) {
	// write your awesome code here
	string str ( st );
	int maxlen = 0 ;
	int s = 0 ;
	int en = 0;
	for (int i = 0 ; i < str.length() ; i++ ) {
		int len1 = expandFromMiddle(str , i , i );
		int len2 = expandFromMiddle(str, i, i + 1);

		int len = max(len1, len2);

		trace(len, i);
		if ( len > maxlen ) {
			maxlen = len;
			s = i - (maxlen - 1) / 2;
			en = i + (maxlen / 2) ;
		}
	}
	trace(str.substr(s , en - s + 1));
	return maxlen;
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		string str ;
		cin >> str;
		longestPalindrome(str);
	}
	return 0;
}
