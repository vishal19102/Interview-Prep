
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
#define mod 1003
typedef pair<string, int> pp;


string str;
static int  memo[101][101][2];

int nWays(int i , int j , int isTrue ) {

	if ( i > j ) return 0 ;

	if ( i == j ) {
		if (isTrue == 1 )
			return str[i] == 'T';
		else
			return str[i] == 'F';
	}

	if (memo[i][j][isTrue] != -1 ) return memo[i][j][isTrue];



	int ans = 0 ;

	for (int k = i + 1; k <= j - 1  ; k += 2) {
		int leftAnsT = nWays(i , k - 1, 1) ;
		int leftAnsF = nWays(i , k - 1, 0) ;
		int rightAnsT = nWays(k + 1, j , 1) ;
		int rightAnsF = nWays(k + 1, j ,  0) ;

		if (str[k] == '&') {
			if (isTrue == 1 ) {
				ans += ( leftAnsT * rightAnsT) % mod ;
			}
			else {
				ans += ((leftAnsT * rightAnsF) % mod + ( rightAnsT * leftAnsF ) % mod + (leftAnsF * rightAnsF) % mod ) % mod ;
			}
		}
		else if (str[k] == '|') {
			if (isTrue == 1 ) {
				ans += ((rightAnsT * leftAnsF) % mod  + (leftAnsT * rightAnsF ) % mod + (leftAnsT * rightAnsT) % mod )  % mod  ;
			}
			else {
				ans += (rightAnsF * leftAnsF) % mod ;
			}
		}
		else if (str[k] == '^') {
			if (isTrue == 1 ) {
				ans += ((leftAnsT * rightAnsF) % mod  + (rightAnsT * leftAnsF) % mod ) % mod ;
			}
			else {
				ans += ((leftAnsF * rightAnsF ) % mod + (rightAnsT * leftAnsT) % mod  ) % mod ;
			}
		}
	}
	return memo[i][j][isTrue] = ans % mod ;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		cin >> str;
		memset(memo , -1 , sizeof(memo));
		cout << nWays(0 , n - 1 , 1 ) << endl ;
	}
	return 0;
}
