
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


int getMaxlength(string str ) {


	int maxL = 0 ;
	int n = str.length();
	for (int i = 0 ; i < n ; i++ ) {
		int lft = i ;
		int rigt = i + 1 ;
		int leftSum = 0;
		int rightSum = 0 ;
		while (lft >= 0 and rigt < n ) {
			leftSum += str[lft] - '0';
			rightSum += str[rigt] - '0';

			if (leftSum == rightSum ) {
				maxL = max(maxL , rigt - lft + 1 ) ;
			}
			lft--;
			rigt++;
		}
	}
	return maxL;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cout << getMaxlength(str) << endl;
	}
	return 0;
}
