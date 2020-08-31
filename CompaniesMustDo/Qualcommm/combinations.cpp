
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


// R , RY , RYY
bool ifSubsequence(string str , int pos ) {

	if (pos >= str.length()) return true ;

	// recursive cases first ..
	if (pos +  2 < str.length() )
		if (str[pos] == 'R' and str[pos + 1] == 'Y' and str[pos + 2] == 'Y' )
			return ifSubsequence(str, pos + 3);

	if (pos + 1 < str.length())
		if (str[pos] == 'R' and str[pos + 1] == 'Y')
			return ifSubsequence(str , pos + 2 );

	if (str[pos] == 'R')
		return ifSubsequence(str, pos + 1);

	return false;
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
		string str ;
		cin >> str ;
		if (ifSubsequence(str , 0 ))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
