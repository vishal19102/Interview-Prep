
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
#define MAX 10001
typedef pair<string, int> pp;

bool isPalindrome[MAX][MAX];

void findAllPalindromes(string X)
{
	int n = X.length();

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
				isPalindrome[i][j] = true;
			else if (X[i] == X[j])
				isPalindrome[i][j] = ((j - i == 1) ? true :
				                      isPalindrome[i + 1][j - 1]);
			else
				isPalindrome[i][j] = false;
		}
	}
}

int minPartitions(string str, int i , int j , vector<vector<int>> &memo ) {

	if ( i >= j ) return 0 ;

	if (isPalindrome[i][j]) return 0 ;

	if (memo[i][j] != -1 ) return memo[i][j];

	int ans = INT_MAX;
	for (int k = i ; k < j ; k++) {

		int left = 0 , right = 0 ;

		if (memo[i][k] != -1 ) left = memo[i][k];
		else
			left = minPartitions(str , i , k , memo);

		if (memo[k + 1][j] != -1 ) right = memo[k + 1][j];
		else
			right =  minPartitions(str, k + 1, j, memo);

		ans = min(ans , left + right + 1 ) ;
	}

	return memo[i][j] = ans ;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int n = str.length();
		trace(n);
		vector<vector<int>> memo ( n + 1 , vector<int> (n + 1 , -1 ));
		findAllPalindromes(str);
		int ans = minPartitions(str , 0 , n - 1 , memo);
		cout << ans << endl;
	}
	return 0;
}
