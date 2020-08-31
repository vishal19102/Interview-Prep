
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
#define MAXVAL 100001


vector<bool> sieve() {

	vector<bool> primes ( MAXVAL , true ) ;

	primes[1] = false ;
	primes[2] = true ;
	for (int i = 2; i * i <= MAXVAL ; i++ ) {
		if (primes[i] == true ) {
			for (int j = i * i ; j <= MAXVAL ; j += i) {
				primes[j] = false ;
			}
		}
	}
	return primes;
}



vector<int>  countPrimeBits() {

	vector<bool> primes ( MAXVAL ) ;
	primes = sieve();
	vector<int>  ps ( MAXVAL , 0 ) ;

	for (int i = 1; i <= MAXVAL ; i++)
	{
		int ones = __builtin_popcount(i);
		ps[i] = ps[i - 1] + (primes[ones] ? 1 : 0);
	}
	return ps ;
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
	vector<int> setBits = countPrimeBits();
	while (t--) {
		int left , right ;
		cin >> left >> right;
		cout << setBits[right] - setBits[left - 1] << endl;
	}
	return 0;
}
