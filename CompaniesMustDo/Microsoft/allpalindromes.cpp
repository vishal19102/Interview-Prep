
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
#define MAX 501
typedef pair<string, int> pp;


bool isPalindrome[MAX][MAX];

int findAllPalindromes(string X)
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

	int count = 0 ;
	for (int i = 0 ; i < X.length() ; i++ ) {
		for (int j = 0 ; j < X.length() ; j++ ) {
			if (i != j  and isPalindrome[i][j] == true )
				count++;
		}
	}
	return count ;
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
		string str;
		cin >> str;
		cout << findAllPalindromes(str) << endl;
	}
	return 0;
}
